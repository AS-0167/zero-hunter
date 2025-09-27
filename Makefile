# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O2 -Iinclude
LDFLAGS = -lm

# Directories
SRCDIR = src
INCDIR = include
OBJDIR = obj
BINDIR = bin

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.c)
OBJECTS = $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)
TARGET = $(BINDIR)/root_finder

# Create directories if they don't exist
$(shell mkdir -p $(OBJDIR) $(BINDIR))

# Default target
all: $(TARGET)

# Link target
$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile source files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJDIR) $(BINDIR)

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build
debug: CFLAGS += -g -DDEBUG
debug: $(TARGET)

# Install (copy to /usr/local/bin)
install: $(TARGET)
	sudo cp $(TARGET) /usr/local/bin/

# Phony targets
.PHONY: all clean run debug install

# Dependencies
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