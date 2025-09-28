# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -Iinclude -Icase_problems/include
LDFLAGS = -lm

# Directories
SRCDIR = src
CASESRCDIR = case_problems/src
INCDIR = include
CASEINCDIR = case_problems/include
OBJDIR = obj
CASEOBJDIR = obj/case
BINDIR = bin

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
CASESOURCES = $(wildcard $(CASESRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
CASEOBJECTS = $(CASESOURCES:$(CASESRCDIR)/%.c=$(CASEOBJDIR)/%.o)
TARGET = $(BINDIR)/root_finder
CASETARGET = $(BINDIR)/case_studies

# Create directories if they don't exist
$(shell mkdir -p $(OBJDIR) $(CASEOBJDIR) $(BINDIR))

# Default target
all: $(TARGET) $(CASETARGET)

# Main toolkit target
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Case studies target
$(CASETARGET): $(CASEOBJECTS) $(filter-out $(OBJDIR)/main.o, $(OBJECTS))
	$(CC) $(CASEOBJECTS) $(filter-out $(OBJDIR)/main.o, $(OBJECTS)) -o $@ $(LDFLAGS)

# Compile main source files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile case study source files
$(CASEOBJDIR)/%.o: $(CASESRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Run the main program
run: $(TARGET)
	./$(TARGET)

# Run case studies
run-cases: $(CASETARGET)
	./$(CASETARGET)

# Debug build
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET) $(CASETARGET)

# Install (copy to /usr/local/bin)
install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/

# Phony targets
.PHONY: all clean run run-cases debug install

# Dependencies for main toolkit
$(OBJDIR)/main.o: $(SRCDIR)/main.c $(INCDIR)/methods.h $(INCDIR)/bisection.h \
                  $(INCDIR)/fixed_point.h $(INCDIR)/newton.h \
                  $(INCDIR)/regula_falsi.h $(INCDIR)/secant.h \
                  $(INCDIR)/stopping.h $(INCDIR)/utils.h

$(OBJDIR)/bisection.o: $(SRCDIR)/bisection.c $(INCDIR)/bisection.h \
                       $(INCDIR)/stopping.h

$(OBJDIR)/fixed_point.o: $(SRCDIR)/fixed_point.c $(INCDIR)/fixed_point.h \
                         $(INCDIR)/stopping.h

$(OBJDIR)/newton.o: $(SRCDIR)/newton.c $(INCDIR)/newton.h \
                    $(INCDIR)/stopping.h

$(OBJDIR)/regula_falsi.o: $(SRCDIR)/regula_falsi.c $(INCDIR)/regula_falsi.h \
                          $(INCDIR)/stopping.h

$(OBJDIR)/secant.o: $(SRCDIR)/secant.c $(INCDIR)/secant.h \
                    $(INCDIR)/stopping.h

$(OBJDIR)/stopping.o: $(SRCDIR)/stopping.c \
                               $(INCDIR)/stopping.h

$(OBJDIR)/utils.o: $(SRCDIR)/utils.c $(INCDIR)/utils.h

# Dependencies for case studies
$(CASEOBJDIR)/case_main.o: $(CASESRCDIR)/case_main.c $(CASEINCDIR)/problem1.h \
                           $(CASEINCDIR)/problem2.h $(CASEINCDIR)/problem3.h \
                           $(CASEINCDIR)/problem4.h $(CASEINCDIR)/problem5.h

$(CASEOBJDIR)/problem1.o: $(CASESRCDIR)/problem1.c $(CASEINCDIR)/problem1.h \
                          $(INCDIR)/bisection.h $(INCDIR)/secant.h

$(CASEOBJDIR)/problem2.o: $(CASESRCDIR)/problem2.c $(CASEINCDIR)/problem2.h \
                          $(INCDIR)/fixed_point.h $(INCDIR)/newton.h

$(CASEOBJDIR)/problem3.o: $(CASESRCDIR)/problem3.c $(CASEINCDIR)/problem3.h \
                          $(INCDIR)/regula_falsi.h $(INCDIR)/bisection.h

$(CASEOBJDIR)/problem4.o: $(CASESRCDIR)/problem4.c $(CASEINCDIR)/problem4.h \
                          $(INCDIR)/newton.h $(INCDIR)/secant.h

$(CASEOBJDIR)/problem5.o: $(CASESRCDIR)/problem5.c $(CASEINCDIR)/problem5.h \
                          $(INCDIR)/bisection.h $(INCDIR)/newton.h