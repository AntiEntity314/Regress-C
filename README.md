# Regress-C

A collection of regression algorithms implemented from scratch in C.

- No external ML libraries
- Just the underlying math (means, variance, covariance, gradients, etc.)
- Each algorithm lives in its own source file

## Currently Implemented

### Simple Linear Regression (`Regress-C.c`)

- Fits a line `y = a + bx` to a set of (x, y) data points
- Uses the **least squares** method
- Computes the fit via mean, variance, and covariance
- Predicts `y` for a user-provided `x`
- Handles the edge case where all X values are identical (zero variance)
- Uses dynamic memory allocation (`calloc`) to support any number of readings

## Planned / Coming Soon

More regression models will be added over time:

- Multiple Linear Regression
- Logistic Regression
- Polynomial Regression

Each new model will:
- Live in its own source file
- Follow the same from-scratch, no-dependency style
- Include the same kind of edge-case handling (bad input, undefined math, etc.)

## Building

Requirements:
- `gcc` (or any C99-compatible compiler)
- The math library (`-lm`)

Command:
```bash
gcc -Wall -std=c99 -O2 -o regress Regress-C.c -lm
```

## Running

```bash
./regress
```

You'll be prompted to enter:
- The number of (x, y) readings
- Each X value
- Each Y value
- An X value to predict Y for

Example session:
```
Enter number of readings: 
5
Enter X value number 1: 
1
...
Final equation: y = 2.200000 + 0.600000x
y = 5.800000
```

## Notes

- Requires C99 or later (uses `for` loop variable declarations like `for(int i=0;...)`)
- On Windows, compile the same way using MinGW-w64:
  ```bash
  gcc -Wall -std=c99 -O2 -o regress.exe Regress-C.c -lm
  ```

## Precompiled Binaries

Currently only a Linux binary is available. Precompiled **Windows (.exe)** and **macOS** binaries are coming soon, so you won't need to compile from source on those platforms.
