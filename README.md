# Zero Hunter - A Root-Finding Toolkit 🔍

![Root Finding](https://img.shields.io/badge/Root-Finding-blue)
![Numerical Methods](https://img.shields.io/badge/Numerical-Methods-green)
![C Programming](https://img.shields.io/badge/C-Programming-orange)

A comprehensive, modular C implementation of numerical root-finding algorithms with configurable stopping criteria and extensive testing capabilities.

## 🌟 Features

- **Five Root-Finding Algorithms** with consistent interfaces
- **Multiple Stopping Criteria** for flexible convergence control
- **Modular Design** for easy extensibility and reuse
- **Comprehensive Testing Framework** for method comparison
- **User-Friendly Menu Interface** for interactive exploration
- **Error Handling** and validation for robust operation
- **Iteration Estimation** for performance prediction

## 📊 Implemented Methods

### 1. Bisection Method
- **Type**: Bracketing method
- **Convergence**: Linear (guaranteed)
- **Requirements**: Function must change sign over interval [a,b]
- **Best for**: Reliable but slower convergence

### 2. Fixed Point Iteration
- **Type**: Open method  
- **Convergence**: Linear (depends on transformation)
- **Requirements**: Suitable g(x) = x transformation
- **Best for**: Simple iterative problems

### 3. Newton's Method
- **Type**: Open method
- **Convergence**: Quadratic (fast)
- **Requirements**: Function derivative available
- **Best for**: Fast convergence when derivative is known

### 4. Regula Falsi (False Position)
- **Type**: Bracketing method
- **Convergence**: Super-linear
- **Requirements**: Function must change sign over interval
- **Best for**: Reliable with faster convergence than bisection

### 5. Secant Method
- **Type**: Open method
- **Convergence**: Super-linear (1.618)
- **Requirements**: Two initial guesses
- **Best for**: Fast convergence without derivative

## 🎯 Stopping Criteria

Three configurable convergence criteria:

1. **Function Value**: `|f(xₖ)| < ε`
2. **Absolute Error**: `|xₖ₊₁ - xₖ| < ε`  
3. **Relative Error**: `|xₖ₊₁ - xₖ|/|xₖ₊₁| < ε`

## 📁 Project Structure

```
zero-hunter/
├── include/
│   ├── methods.h          # Common types and structures
│   ├── bisection.h        # Bisection method header
│   ├── fixed_point.h      # Fixed point iteration header
│   ├── newton.h           # Newton's method header
│   ├── regula_falsi.h     # Regula falsi method header
│   ├── secant.h           # Secant method header
│   ├── stopping_criteria.h# Stopping criteria functions
│   └── utils.h            # Utility functions and examples
├── src/
│   ├── main.c             # Main program with menu interface
│   ├── bisection.c        # Bisection method implementation
│   ├── fixed_point.c      # Fixed point iteration implementation
│   ├── newton.c           # Newton's method implementation
│   ├── regula_falsi.c     # Regula falsi implementation
│   ├── secant.c           # Secant method implementation
│   ├── stopping_criteria.c# Stopping criteria implementation
│   └── utils.c            # Utility functions implementation
└── Makefile              # Build configuration
```

## 🚀 Quick Start

### Prerequisites
- GCC Compiler
- GNU Make
- Linux/macOS/Windows (with WSL)

### Building the Project

```bash
# Clone or download the project
cd zero-hunter

# Build the project
make

# Run the program
make run

# Or run directly
./bin/root_finder
```

### Clean Build
```bash
make clean          # Remove build files
make debug          # Build with debug symbols
```

## 🎮 Usage Examples

### Interactive Mode
Run the program and follow the menu prompts:

```
=== Generalized Root-Finding Toolkit ===

=== Root-Finding Methods ===
1. Bisection Method
2. Fixed Point Iteration  
3. Newton's Method
4. Regula Falsi Method
5. Secant Method
6. Test All Methods
7. Compare Stopping Criteria
0. Exit
```

### Available Test Functions
1. **f(x) = x² - 4** (Root: ±2)
2. **f(x) = x³ - x - 2** (Root: ~1.521)
3. **f(x) = x³ - 2x - 5** (Root: ~2.094) 
4. **f(x) = cos(x) - x** (Root: ~0.739)
5. **f(x) = x - e^(-x)** (Root: ~0.567)

## 📋 Demo Scenarios

### Demo 1: Basic Function Test
**Input:**
```
Choice: 6 (Test All Methods)
Function: 1
Tolerance: 0.0001
Max Iterations: 50
Interval: [1, 3]
Initial guess: 1.5
```

**Expected Output:**
```
=== Testing All Methods ===
Method          Root        Iterations Final Error
-------------------------------------------------
Bisection       2.000000    15         6.10e-05
Fixed Point     2.000000    8          7.45e-05
Newton          2.000000    5          6.94e-07
Regula Falsi    2.000000    7          6.83e-05
Secant          2.000000    7          1.97e-07
```

### Demo 2: Transcendental Equation
**Input:**
```
Choice: 6 (Test All Methods)
Function: 4 (cos(x) - x)
Tolerance: 1e-6
Max Iterations: 100
Interval: [0.5, 1.0]
Initial guess: 0.7
```

**Expected Output:**
```
=== Testing All Methods ===
Method          Root        Iterations Final Error
-------------------------------------------------
Bisection       0.739085    20         9.54e-07
Fixed Point     0.739085    6          8.64e-07
Newton          0.739085    4          1.11e-08
Regula Falsi    0.739085    4          2.22e-07
Secant          0.739085    4          1.11e-08
```

### Demo 3: High Precision
**Input:**
```
Choice: 3 (Newton's Method)
Function: 5 (x - e^(-x))
Tolerance: 1e-10
Max Iterations: 20
Initial guess: 0.5
Stopping criterion: 2 (Absolute error)
```

**Expected Output:**
```
Newton's Method Results:
Root: 0.5671432904
Iterations: 4
Final Error: 8.76e-12
```

### Demo 4: Stopping Criteria Comparison
**Input:**
```
Choice: 7 (Compare Stopping Criteria)
Function: 3 (x³ - 2x - 5)
Tolerance: 1e-6
Max Iterations: 50
Interval: [2, 3]
Initial guess: 2.5
```

**Expected Output:**
```
=== Comparing Stopping Criteria ===
Bisection Method:
Criterion        Root        Iterations
------------------------------------
|f(x)|          2.094551    20
|x_k+1 - x_k|   2.094551    21
Relative Error  2.094551    20

Newton's Method:
Criterion        Root        Iterations
------------------------------------
|f(x)|          2.094551    4
|x_k+1 - x_k|   2.094551    5
Relative Error  2.094551    4
```

## 🔧 Advanced Usage

### Custom Functions
To add your own functions, modify `utils.c`:

```c
// Add your function
double custom_function(double x) {
    return x*x*x - 2*x - 5; // Example: x³ - 2x - 5
}

// Add derivative (for Newton's method)
double custom_derivative(double x, double h) {
    return (custom_function(x+h) - custom_function(x-h)) / (2*h);
}
```

### Programmatic Usage
The library can be used in other C programs:

```c
#include "include/methods.h"
#include "include/bisection.h"

// Find root of x² - 4 over [1,3]
RootResult result = bisection_method(f1, 1.0, 3.0, 1e-6, 100, STOPPING_ABSOLUTE_ERROR);
printf("Root: %f, Iterations: %d\n", result.root, result.iterations);
```

## 📊 Performance Characteristics

| Method | Convergence Rate | Bracketing? | Derivative Required | Best Use Case |
|--------|------------------|-------------|---------------------|---------------|
| Bisection | Linear (1) | Yes | No | Guaranteed convergence |
| Fixed Point | Linear | No | No | Simple transformations |
| Newton | Quadratic (2) | No | Yes | Fast convergence |
| Regula Falsi | Super-linear | Yes | No | Reliable & faster than bisection |
| Secant | Super-linear (1.618) | No | No | No derivative, fast convergence |

## 🐛 Troubleshooting

### Common Issues

1. **"f(a) and f(b) must have opposite signs"**
   - Solution: Choose an interval where the function changes sign

2. **"Derivative is too small"**
   - Solution: Try a different initial guess or method

3. **Method doesn't converge**
   - Solution: Increase max iterations or try a bracketing method

4. **Build errors**
   - Solution: Ensure GCC and Make are installed: `sudo apt install build-essential`

### Debug Build
```bash
make debug    # Build with debug symbols
gdb ./bin/root_finder  # Debug with GDB
```

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

1. Fork the project
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is open source and available under the [MIT License](LICENSE).

## 🙏 Acknowledgments

- Numerical Methods course materials
- Burden & Faires "Numerical Analysis" textbook
- Open source numerical computing community

---

**Zero Hunter** - Because every function deserves to find its roots! 🌱

*Built with passion for numerical computing and clean code architecture.*