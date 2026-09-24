# Department of Computer Science & Engineering
## Rajshahi University of Engineering & Technology (RUET)

---

### Course Title: Numerical Methods Laboratory
### Course Code: CSE-2204
### Student Information:
- **Name:** Farhan
- **Roll No:** 2303011
- **Academic Year / Semester:** 2nd Year, 2nd Semester
- **Department:** Computer Science & Engineering, RUET

---

# Table of Contents
1. [Module 1: Foundations of Numerical Methods & Modeling (Template)](#module-1-foundations-of-numerical-methods--modeling-template)
2. [Module 2: Solution of Algebraic and Transcendental Equations](#module-2-solution-of-algebraic-and-transcendental-equations)
   - [Experiment 2.1: Root-Finding for Transcendental Equations (Bisection, Regula Falsi, Newton-Raphson, Secant)](#experiment-21-root-finding-for-transcendental-equations-bisection-regula-falsi-newton-raphson-secant)
   - [Experiment 2.2: Ramanujan’s Method for Finding the Smallest Root](#experiment-22-ramanujans-method-for-finding-the-smallest-root)
   - [Experiment 2.3: Newton-Raphson Method for Systems of Nonlinear Equations](#experiment-23-newton-raphson-method-for-systems-of-nonlinear-equations)
3. [Module 3: Finite Differences & Interpolation](#module-3-finite-differences--interpolation)
   - [Experiment 3.1: Generation and Verification of Finite Difference Tables](#experiment-31-generation-and-verification-of-finite-difference-tables)
   - [Experiment 3.2: Estimation of Missing Tabular Values Using Finite Difference Operators](#experiment-32-estimation-of-missing-tabular-values-using-finite-difference-operators)
   - [Experiment 3.3: Polynomial Interpolation (Newton’s Forward, Backward, and Gauss’s Central Difference)](#experiment-33-polynomial-interpolation-newtons-forward-backward-and-gausss-central-difference)
4. [Module 4: Least-Squares Curve Fitting](#module-4-least-squares-curve-fitting)
   - [Experiment 4.1: Least-Squares Fitting of a Straight Line](#experiment-41-least-squares-fitting-of-a-straight-line)
   - [Experiment 4.2: Least-Squares Fitting of a Second-Degree Parabola](#experiment-42-least-squares-fitting-of-a-second-degree-parabola)
   - [Experiment 4.3: Nonlinear Curve Fitting via Linearization (Exponential Law)](#experiment-43-nonlinear-curve-fitting-via-linearization-exponential-law)

---

# Module 1: Foundations of Numerical Methods & Modeling (Template)

> *Note: This section serves as the formal structural template for reports under Chapter 1 as specified in the course laboratory guidelines.*

### Experiment No: 01 (Template)
### Experiment Name: Mathematical Modeling & Euler’s Method

#### 1. Objective
To formulate a differential-equation model of a physical process and solve it numerically using Euler’s first-order method, analyzing the truncation error and convergence with varying step size $h$.

#### 2. Theory
Euler’s method approximates the solution of an initial-value problem $\frac{dy}{dt} = \phi(t, y)$ with $y(t_0) = y_0$ by replacing the continuous derivative with a forward finite-difference slope over a discrete increment $h$:
$$y_{i+1} = y_i + \phi(t_i, y_i) h \tag{1.1}$$
The local truncation error is $\mathcal{O}(h^2)$, while the accumulated global truncation error across a fixed domain is $\mathcal{O}(h)$. Consequently, halving the step size $h$ roughly halves the global error.

#### 3. Algorithm
```text
Algorithm: Euler's Method for First-Order ODE
Input: Slope function phi(t, y), initial values t0, y0, step size h, target time t_end
Output: Tabular trajectory of (t, y)

1. Set t <- t0, y <- y0
2. Print header and initial state (t, y)
3. While t < t_end do:
     y <- y + phi(t, y) * h
     t <- t + h
     Print current state (t, y)
4. End While
5. Return final y
```

#### 4. Sample Input
- **Differential Equation:** $\frac{dv}{dt} = g - \frac{c}{m}v$
- **Parameters:** $g = 9.8\text{ m/s}^2,\; c = 12.5\text{ kg/s},\; m = 68.1\text{ kg}$
- **Initial Condition:** $t_0 = 0.0\text{ s},\; v_0 = 0.0\text{ m/s}$
- **Integration Range:** $h = 2.0\text{ s},\; t_{\text{end}} = 10.0\text{ s}$

#### 5. Output / Results
| Time $t$ (s) | Numerical Estimate $y_{\text{Euler}}$ (m/s) | Analytical True Value $y_{\text{true}}$ (m/s) | Relative Error $\vert \varepsilon_t \vert$ (%) |
| :---: | :---: | :---: | :---: |
| 0.0 | 0.0000 | 0.0000 | — |
| 2.0 | 19.6000 | 16.4050 | 19.48% |
| 4.0 | 32.0000 | 27.7690 | 15.24% |
| 6.0 | 39.8517 | 35.6417 | 11.81% |
| 8.0 | 44.8248 | 41.0999 | 9.06% |
| 10.0 | 47.9675 | 44.8734 | 6.89% |

**Final Value:** At $t = 10.0\text{ s}$, $y(10) \approx 47.9675\text{ m/s}$ (True value: $44.8734\text{ m/s}$).

#### 6. Discussion
Euler’s method consistently overestimates the velocity profile due to positive truncation error stemming from the drop in derivative over each finite time interval. As step size $h$ decreases, the numerical trajectory approaches the exact analytical curve at rate $\mathcal{O}(h)$, although choosing an excessively small $h$ incurs floating-point round-off accumulation.

#### 7. Conclusion
Euler’s method provides a straightforward numerical procedure for solving initial-value ODEs. Its first-order accuracy was verified against the analytical solution, demonstrating the direct trade-off between step size and approximation accuracy.

---

# Module 2: Solution of Algebraic and Transcendental Equations

---

### Experiment 2.1: Root-Finding for Transcendental Equations (Bisection, Regula Falsi, Newton-Raphson, Secant)

#### 1. Objective
To compute the real root of a nonlinear transcendental equation using bracketing (Bisection, Regula Falsi) and open (Newton-Raphson, Secant) iterative methods, comparing their convergence rates and computational efficiencies.

#### 2. Theory
Given a continuous non-linear function $f(x) = 0$, bracketing methods require an initial interval $[a, b]$ such that $f(a)f(b) < 0$. 
- **Bisection Method:** Repeatedly halves the bracket:
  $$x_{k} = \frac{a_k + b_k}{2} \tag{2.1}$$
  Guaranteed linear convergence with rate $\frac{1}{2}$.
- **Method of False Position (Regula Falsi):** Connects $(a, f(a))$ and $(b, f(b))$ by a chord, obtaining:
  $$x_k = \frac{a f(b) - b f(a)}{f(b) - f(a)} \tag{2.2}$$
- **Newton-Raphson Method:** Employs the first-order Taylor expansion slope:
  $$x_{k+1} = x_k - \frac{f(x_k)}{f'(x_k)} \tag{2.3}$$
  Exhibits quadratic convergence ($p=2$) given a suitable initial guess.
- **Secant Method:** Approximates $f'(x)$ using two prior approximations:
  $$x_{k+1} = \frac{x_{k-1}f(x_k) - x_k f(x_{k-1})}{f(x_k) - f(x_{k-1})} \tag{2.4}$$
  Exhibits superlinear convergence ($p \approx 1.618$).

#### 3. Algorithm
```text
Algorithm: Root-Finding Driver
Input: Function f(x), derivative f'(x), bracket [a, b] or guesses x0, x1, tolerance tol
Output: Approximate root x_star and iteration count k

Procedure Bisection(a, b, tol):
    While abs(b - a) > tol:
        x <- (a + b) / 2
        If f(a) * f(x) > 0 then a <- x else b <- x
    Return x

Procedure NewtonRaphson(x0, tol):
    x <- x0
    Loop:
        x_new <- x - f(x) / f'(x)
        If abs(x_new - x) < tol then Return x_new
        x <- x_new

Procedure Secant(x0, x1, tol):
    Loop:
        x_new <- (x0 * f(x1) - x1 * f(x0)) / (f(x1) - f(x0))
        If abs(x_new - x1) < tol then Return x_new
        x0 <- x1; x1 <- x_new
```

#### 4. Sample Input
- **Equation:** $f(x) = e^{-x} - \sin(x) = 0$
- **Derivative (for Newton-Raphson):** $f'(x) = -e^{-x} - \cos(x)$
- **Stopping Tolerance:** $\varepsilon = 10^{-3}$
- **Initial Guesses / Intervals:** 
  - Bisection & Regula Falsi: $a = 0.0,\; b = 1.0$ (since $f(0) = 1.0 > 0$ and $f(1) = -0.47359 < 0$)
  - Newton-Raphson: $x_0 = 0.5$
  - Secant: $x_0 = 0.4,\; x_1 = 0.9$

#### 5. Output / Results

##### (a) Bisection Method ($a=0.0, b=1.0$)
| Iteration $k$ | $a$ | $b$ | Midpoint $x_k$ | $f(x_k)$ | Width $(b - a)$ |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 0.00000 | 1.00000 | 0.50000 | $+1.27105 \times 10^{-1}$ | 1.00000 |
| 2 | 0.50000 | 1.00000 | 0.75000 | $-2.09272 \times 10^{-1}$ | 0.50000 |
| 3 | 0.50000 | 0.75000 | 0.62500 | $-4.98358 \times 10^{-2}$ | 0.25000 |
| 4 | 0.50000 | 0.62500 | 0.56250 | $+3.64802 \times 10^{-2}$ | 0.12500 |
| 5 | 0.56250 | 0.62500 | 0.59375 | $-7.22068 \times 10^{-3}$ | 0.06250 |
| 6 | 0.56250 | 0.59375 | 0.57812 | $+1.44946 \times 10^{-2}$ | 0.03125 |
| 7 | 0.57812 | 0.59375 | 0.58594 | $+3.60308 \times 10^{-3}$ | 0.01562 |
| 8 | 0.58594 | 0.59375 | 0.58984 | $-1.81728 \times 10^{-3}$ | 0.00781 |
| 9 | 0.58594 | 0.58984 | 0.58789 | $+8.90782 \times 10^{-4}$ | 0.00391 |
| 10 | 0.58789 | 0.58984 | 0.58887 | $-4.63777 \times 10^{-4}$ | 0.00098 |

*Root:* $x \approx 0.58887$ (10 iterations).

##### (b) Regula Falsi Method ($a=0.0, b=1.0$)
| Iteration $k$ | $a$ | $b$ | Interpolated $x_k$ | $f(x_k)$ | Residual $\vert f(x_k) \vert$ |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 0.00000 | 1.00000 | 0.67861 | $-1.20395 \times 10^{-1}$ | $1.20395 \times 10^{-1}$ |
| 2 | 0.00000 | 0.67861 | 0.60569 | $-2.36341 \times 10^{-2}$ | $2.36341 \times 10^{-2}$ |
| 3 | 0.00000 | 0.60569 | 0.59171 | $-4.39716 \times 10^{-3}$ | $4.39716 \times 10^{-3}$ |
| 4 | 0.00000 | 0.59171 | 0.58912 | $-8.09891 \times 10^{-4}$ | $8.09891 \times 10^{-4}$ |

*Root:* $x \approx 0.58912$ (4 iterations).

##### (c) Newton-Raphson Method ($x_0 = 0.5$)
| Iteration $k$ | $x_k$ | $f(x_k)$ | $f'(x_k)$ | Step $\vert x_k - x_{k-1} \vert$ |
| :---: | :---: | :---: | :---: | :---: |
| 1 | 0.58564 | $+4.01128 \times 10^{-3}$ | $-1.39002$ | $8.56438 \times 10^{-2}$ |
| 2 | 0.58853 | $+4.62025 \times 10^{-6}$ | $-1.38676$ | $2.88560 \times 10^{-3}$ |
| 3 | 0.58853 | $+6.16096 \times 10^{-12}$ | $-1.38676$ | $3.33135 \times 10^{-6}$ |

*Root:* $x \approx 0.58853$ (3 iterations).

##### (d) Secant Method ($x_0 = 0.4, x_1 = 0.9$)
| Iteration $k$ | $x_{k+1}$ | $f(x_{k+1})$ | Step $\vert x_{k+1} - x_k \vert$ |
| :---: | :---: | :---: | :---: |
| 1 | 0.61356 | $-3.43643 \times 10^{-2}$ | $2.86438 \times 10^{-1}$ |
| 2 | 0.58481 | $+5.16595 \times 10^{-3}$ | $2.87484 \times 10^{-2}$ |
| 3 | 0.58857 | $-5.22153 \times 10^{-5}$ | $3.75694 \times 10^{-3}$ |
| 4 | 0.58853 | $-7.75981 \times 10^{-8}$ | $3.75936 \times 10^{-5}$ |

*Root:* $x \approx 0.58853$ (4 iterations).

#### 6. Discussion
Newton-Raphson converged the fastest (3 iterations) owing to its quadratic convergence rate, though it requires analytical evaluation of $f'(x)$. The Secant method achieved comparable precision in 4 iterations without derivative computations. Bisection was the slowest (10 iterations) but guaranteed unconditional convergence.

#### 7. Conclusion
All four methods successfully located the root at $x \approx 0.5885$. Newton-Raphson and Secant methods proved computationally superior in iteration counts, while bracketing methods offered robustness against divergence.

---

### Experiment 2.2: Ramanujan’s Method for Finding the Smallest Root

#### 1. Objective
To determine the smallest real root of an algebraic or transcendental polynomial equation using Ramanujan’s recursive series expansion method.

#### 2. Theory
Ramanujan’s method computes the smallest root of an equation written in the form:
$$f(x) = 1 - \sum_{i=1}^{\infty} a_i x^i = 0 \tag{2.5}$$
Writing $\frac{1}{f(x)} = \sum_{n=0}^{\infty} b_n x^n$ with $b_0 = 1$, the coefficients $b_n$ satisfy the convolution recurrence:
$$b_n = \sum_{j=1}^{n} a_j b_{n-j} \tag{2.6}$$
As $n \to \infty$, the ratio of consecutive coefficients converges to the smallest root $\xi$:
$$\lim_{n \to \infty} \frac{b_{n-1}}{b_n} = \xi \tag{2.7}$$

#### 3. Algorithm
```text
Algorithm: Ramanujan's Method for Smallest Root
Input: Coefficient array a = [a1, a2, ..., am], tolerance tol
Output: Smallest root xi

1. Initialize array b <- [1, a[0]]
2. i <- 2
3. Loop:
     sum_val <- 0
     For j from 0 to min(i-1, len(a)-1):
         sum_val <- sum_val + b[len(b) - 1 - j] * a[j]
     Append sum_val to b
     i <- i + 1
     If abs((b[last-1] / b[last]) - (b[last-2] / b[last-1])) < tol:
         Return b[last-1] / b[last]
```

#### 4. Sample Input
- **Equation:** $1 - \frac{3}{2}x - \frac{1}{4}x^2 + \frac{1}{48}x^3 = 0$
- **Coefficients:** $a_1 = \frac{3}{2} = 1.5,\; a_2 = \frac{1}{4} = 0.25,\; a_3 = -\frac{1}{48} \approx -0.020833$
- **Stopping Tolerance:** $\vert r_n - r_{n-1} \vert < 10^{-3}$

#### 5. Output / Results
| Index $n$ | Computed $b_n$ | Root Ratio $r_n = b_{n-1}/b_n$ | Difference $\vert r_n - r_{n-1} \vert$ |
| :---: | :---: | :---: | :---: |
| 1 | $1.50000$ | $0.66667$ | — |
| 2 | $2.50000$ | $0.60000$ | $0.06667$ |
| 3 | $4.10417$ | $0.60914$ | $0.00914$ |
| 4 | $6.75000$ | $0.60802$ | $0.00111$ |
| 5 | $11.09896$ | $0.60817$ | $0.00014$ |

**Final Value:** The smallest root is $\xi \approx 0.60817$ (terminated at $n=5$).

#### 6. Discussion
Ramanujan’s method directly yields the root of smallest magnitude without requiring initial guess bracketing or derivative evaluations. Convergence is monotonic and rapid when higher-order roots are well separated from the dominant smallest root.

#### 7. Conclusion
Ramanujan’s recursive method successfully computed the smallest root to four decimal places ($0.6082$) in 5 steps, confirming its utility for power series expansions.

---

### Experiment 2.3: Newton-Raphson Method for Systems of Nonlinear Equations

#### 1. Objective
To solve a system of coupled nonlinear algebraic equations simultaneously using the multidimensional Newton-Raphson formulation.

#### 2. Theory
For two coupled nonlinear equations $f(x, y) = 0$ and $g(x, y) = 0$, linearizing via bivariate Taylor series yields the matrix correction system:
$$\begin{pmatrix} \frac{\partial f}{\partial x} & \frac{\partial f}{\partial y} \\ \frac{\partial g}{\partial x} & \frac{\partial g}{\partial y} \end{pmatrix} \begin{pmatrix} h \\ k \end{pmatrix} = \begin{pmatrix} -f(x, y) \\ -g(x, y) \end{pmatrix} \tag{2.8}$$
Applying Cramer's rule with Jacobian determinant $D = f_x g_y - f_y g_x \neq 0$:
$$h = \frac{-f g_y + g f_y}{D}, \quad k = \frac{-g f_x + f g_x}{D} \tag{2.9}$$
The iterative update is:
$$x_{k+1} = x_k + h, \quad y_{k+1} = y_k + k \tag{2.10}$$

#### 3. Algorithm
```text
Algorithm: Multivariable Newton-Raphson Solver
Input: Functions f(x, y), g(x, y), partial derivatives fx, fy, gx, gy, initial guess (x0, y0), tolerance eps
Output: Solution vector (x*, y*)

1. Set x <- x0, y <- y0
2. Loop:
     D <- fx(x, y) * gy(x, y) - fy(x, y) * gx(x, y)
     h <- (-f(x, y) * gy(x, y) - g(x, y) * fy(x, y)) / D
     k <- (-f(x, y) * gx(x, y) - g(x, y) * fx(x, y)) / D
     x <- x + h
     y <- y + k
     If abs(h) < eps and abs(k) < eps then:
         Return (x, y)
```

#### 4. Sample Input
- **Nonlinear System:**
  $$\begin{aligned} f(x, y) &= 3y x^2 - 10x + 7 = 0 \\ g(x, y) &= y^2 - 5y + 4 = 0 \end{aligned}$$
- **Initial Guesses:** $x_0 = 2.0,\; y_0 = 2.0$
- **Convergence Tolerance:** $\varepsilon = 10^{-5}$

#### 5. Output / Results
| Iteration $k$ | $x_k$ | $y_k$ | Correction $h$ | Correction $k$ | $f(x_k, y_k)$ | $g(x_k, y_k)$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 2.000000 | 2.000000 | $-2.500000$ | $-2.000000$ | $1.100000 \times 10^{1}$ | $-2.000000$ |
| 2 | $-0.500000$ | 0.000000 | $+1.140000$ | $+0.800000$ | $1.200000 \times 10^{1}$ | $+4.000000$ |
| 3 | 0.640000 | 0.800000 | $+0.195112$ | $+0.188235$ | $1.583040$ | $+0.640000$ |
| 4 | 0.835112 | 0.988235 | $+0.137073$ | $+0.011719$ | $0.716501$ | $3.543253 \times 10^{-2}$ |
| 5 | 0.972185 | 0.999954 | $+0.027194$ | $+4.577637 \times 10^{-5}$ | $0.113451$ | $1.373333 \times 10^{-4}$ |
| 6 | 0.999379 | 1.000000 | $+6.207640 \times 10^{-4}$ | $+6.984919 \times 10^{-10}$ | $2.485371 \times 10^{-3}$ | $2.095476 \times 10^{-9}$ |
| 7 | 1.000000 | 1.000000 | $+2.900579 \times 10^{-7}$ | $0.000000$ | $1.160232 \times 10^{-6}$ | $0.000000$ |

**Final Solution Vector:** $(x^*, y^*) = (1.000000, 1.000000)$ in 7 iterations.

#### 6. Discussion
The Jacobian matrix remained non-singular throughout iterations. As the iterates entered the local convergence domain of root $(1, 1)$, quadratic convergence occurred, driving residuals in both $f$ and $g$ below machine-level thresholds.

#### 7. Conclusion
The multivariable Newton-Raphson scheme accurately solved the non-linear system in 7 iterations, yielding $(x, y) = (1.0000, 1.0000)$.

---

# Module 3: Finite Differences & Interpolation

---

### Experiment 3.1: Generation and Verification of Finite Difference Tables

#### 1. Objective
To construct a forward difference table for equally spaced discrete data and verify the fundamental theorem of finite differences for polynomial functions.

#### 2. Theory
For values $y_i = f(x_i)$ at nodes $x_i = x_0 + ih$, the first forward difference is $\Delta y_i = y_{i+1} - y_i$. Higher-order differences are defined recursively:
$$\Delta^k y_i = \Delta^{k-1} y_{i+1} - \Delta^{k-1} y_i \tag{3.1}$$
**Fundamental Theorem of Finite Differences:** If $f(x)$ is a polynomial of degree $n$, its $n$-th difference is constant ($\Delta^n y = n! a_n h^n$), and all subsequent differences of order $(n+1)$ and higher vanish identically ($\Delta^{n+1} y = 0$).

#### 3. Algorithm
```text
Algorithm: Forward Difference Table Construction
Input: Function fx or ordinate array y, grid nodes x
Output: 2D Table D where D[k][i] = Delta^k y_i

1. n <- len(x)
2. Initialize 2D array D with n rows
3. For i from 0 to n-1:
     D[0][i] <- fx(x[i])
4. For k from 1 to n-1:
     For j from 0 to n - 1 - k:
         D[k][j] <- D[k-1][j+1] - D[k-1][j]
5. Return D
```

#### 4. Sample Input
- **Function:** $f(x) = x^3$
- **Nodes:** $x \in \{0, 1, 2, 3, 4, 5\}$, step size $h = 1$

#### 5. Output / Results
| $x$ | $y = x^3$ | $\Delta y$ | $\Delta^2 y$ | $\Delta^3 y$ | $\Delta^4 y$ | $\Delta^5 y$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 0 | 0 | 1 | 6 | 6 | 0 | 0 |
| 1 | 1 | 7 | 12 | 6 | 0 | — |
| 2 | 8 | 19 | 18 | 6 | — | — |
| 3 | 27 | 37 | 24 | — | — | — |
| 4 | 64 | 61 | — | — | — | — |
| 5 | 125 | — | — | — | — | — |

**Leading Differences:** $\Delta y_0 = 1, \Delta^2 y_0 = 6, \Delta^3 y_0 = 6, \Delta^4 y_0 = 0$.

#### 6. Discussion
Because the input function is a cubic polynomial ($n=3$), the third differences are constant ($\Delta^3 y = 3! \cdot 1 \cdot (1)^3 = 6$), and the fourth and higher differences evaluate to zero, confirming theoretical predictions.

#### 7. Conclusion
The forward difference table was successfully generated. The constant value of the 3rd differences confirmed the order of the underlying cubic polynomial.

---

### Experiment 3.2: Estimation of Missing Tabular Values Using Finite Difference Operators

#### 1. Objective
To estimate an unknown missing entry in an equally spaced tabular data sequence using operator relations between Shift ($E$) and Difference ($\Delta$).

#### 2. Theory
The shift operator $E$ and difference operator $\Delta$ satisfy $E = 1 + \Delta$. If $n$ values of an $n$-th degree polynomial are given with one missing entry, then $\Delta^n y_0 = 0$. Expanding this via the binomial theorem:
$$(E - 1)^n y_0 = \sum_{i=0}^{n} (-1)^i \binom{n}{i} y_{n-i} = 0 \tag{3.2}$$
The coefficients correspond to alternating entries of row $n$ of Pascal's triangle, allowing algebraic isolation of the unknown entry.

#### 3. Algorithm
```text
Algorithm: Missing Value Estimation via Pascal's Triangle
Input: List y containing numbers and one missing token '*'
Output: Estimated missing value

1. n <- len(y) - 1
2. Compute row n of Pascal's triangle: C <- PascalRow(n)
3. sum_val <- 0, missing_coeff <- 0
4. For i from 0 to n:
     coeff <- (-1)^i * C[i]
     If y[i] is '*':
         missing_coeff <- coeff
     Else:
         sum_val <- sum_val + coeff * y[i]
5. Return -sum_val / missing_coeff
```

#### 4. Sample Input
- **Dataset:** $y = [1, 3, 9, 31, *]$
- **Number of intervals:** $n = 4$
- **Condition:** $\Delta^4 y_0 = (E - 1)^4 y_0 = 0$

#### 5. Output / Results
Binomial Expansion:
$$y_4 - 4y_3 + 6y_2 - 4y_1 + y_0 = 0$$
Substituting known tabular values:
$$y_4 - 4(31) + 6(9) - 4(3) + 1 = 0$$
$$y_4 - 124 + 54 - 12 + 1 = 0 \implies y_4 - 81 = 0 \implies y_4 = 81.0$$

**Final Value:** The missing tabular value is $81.0$.

#### 6. Discussion
The method utilizes the property that an underlying polynomial of degree $< 4$ has vanishing 4th differences. The calculated value $81.0$ matches the fourth power sequence progression and restores continuity to the dataset.

#### 7. Conclusion
Using symbolic finite-difference operator relationships, the missing tabular value was determined as $81.0$ without explicit curve regression.

---

### Experiment 3.3: Polynomial Interpolation (Newton’s Forward, Backward, and Gauss’s Central Difference)

#### 1. Objective
To interpolate values of an unknown function at non-tabular points using Newton’s Forward, Newton’s Backward, and Gauss’s Central Difference formulae.

#### 2. Theory
Let $h$ be the uniform step size and $p = \frac{x - x_{\text{base}}}{h}$.
- **Newton’s Forward Interpolation** (base $x_0$, used near start of table):
  $$y(x) = y_0 + p \Delta y_0 + \frac{p(p-1)}{2!} \Delta^2 y_0 + \frac{p(p-1)(p-2)}{3!} \Delta^3 y_0 + \cdots \tag{3.3}$$
- **Newton’s Backward Interpolation** (base $x_n$, used near end of table):
  $$y(x) = y_n + p \nabla y_n + \frac{p(p+1)}{2!} \nabla^2 y_n + \frac{p(p+1)(p+2)}{3!} \nabla^3 y_n + \cdots \tag{3.4}$$
- **Gauss’s Central Difference Interpolation** (base $x_0$ near center):
  $$y(x) = y_0 + p \Delta y_0 + \frac{p(p-1)}{2!} \Delta^2 y_{-1} + \frac{(p+1)p(p-1)}{3!} \Delta^3 y_{-1} + \cdots \tag{3.5}$$

#### 3. Algorithm
```text
Algorithm: Polynomial Interpolation
Input: Nodes x, ordinates y, target value X, mode (forward/backward/central)
Output: Interpolated value y_target

1. Build complete difference table D from y
2. If mode is Forward:
     base <- x[0], p <- (X - base) / h
     coeffs <- ForwardBinomials(p, n)
     diffs <- LeadingDiagonal(D)
3. Else If mode is Backward:
     base <- x[n-1], p <- (X - base) / h
     coeffs <- BackwardBinomials(p, n)
     diffs <- TrailingDiagonal(D)
4. Else If mode is Central:
     base <- x[center], p <- (X - base) / h
     coeffs <- CentralBinomials(p, n)
     diffs <- CenterZigzag(D)
5. Compute y_target <- Sum(coeff[i] * diff[i])
6. Return y_target
```

#### 4. Sample Input
- **Dataset A (Forward & Backward):**
  - $x = [1, 3, 5, 7],\; y = [24, 120, 336, 720],\; h = 2$
  - Target: evaluate at $x = 8$.
- **Dataset B (Gauss Central Difference):**
  - $x = [1.00, 1.05, 1.10, 1.15, 1.20, 1.25, 1.30]$
  - $y = [2.7183, 2.8577, 3.0042, 3.1582, 3.3201, 3.4903, 3.6693]$
  - Target: evaluate $e^{1.17}$ at $x = 1.17$ with central anchor $x_0 = 1.15,\; h = 0.05$.

#### 5. Output / Results

##### Difference Table for Dataset A:
| $x$ | $y$ | $\Delta y$ | $\Delta^2 y$ | $\Delta^3 y$ |
| :---: | :---: | :---: | :---: | :---: |
| 1 | 24 | 96 | 120 | 48 |
| 3 | 120 | 216 | 168 | — |
| 5 | 336 | 384 | — | — |
| 7 | 720 | — | — | — |

- **Newton's Forward Interpolation ($x=8$):**
  $p = \frac{8 - 1}{2} = 3.5$
  $$y(8) = 24 + 3.5(96) + \frac{3.5(2.5)}{2}(120) + \frac{3.5(2.5)(1.5)}{6}(48) = 990.0$$
- **Newton's Backward Interpolation ($x=8$):**
  $p = \frac{8 - 7}{2} = 0.5$
  $$y(8) = 720 + 0.5(384) + \frac{0.5(1.5)}{2}(168) + \frac{0.5(1.5)(2.5)}{6}(48) = 990.0$$

##### Central Difference Table for Dataset B:
| $x$ | $y = e^x$ | $\Delta y$ | $\Delta^2 y$ | $\Delta^3 y$ | $\Delta^4 y$ |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 1.00 | 2.7183 | 0.1394 | 0.0071 | 0.0004 | 0.0000 |
| 1.05 | 2.8577 | 0.1465 | 0.0075 | 0.0004 | 0.0000 |
| 1.10 | 3.0042 | 0.1540 | 0.0079 | 0.0004 | 0.0001 |
| **1.15** | **3.1582** | **0.1619** | **0.0083** | **0.0005** | — |
| 1.20 | 3.3201 | 0.1702 | 0.0088 | — | — |
| 1.25 | 3.4903 | 0.1790 | — | — | — |
| 1.30 | 3.6693 | — | — | — | — |

- **Gauss Central Difference Interpolation ($x=1.17$):**
  For anchor node $x_0 = 1.15$, $p = \frac{1.17 - 1.15}{0.05} = 0.40$
  $$y(1.17) = 3.1582 + (0.40)(0.1619) + \frac{(0.40)(-0.60)}{2}(0.0079) \approx 3.2221$$

#### 6. Discussion
Both forward and backward formulae yielded identical results ($990.0$) at $x=8$ because the data follows an exact polynomial of degree 3. Backward interpolation is computationally more stable for points near the end of the table ($p=0.5$ vs $p=3.5$). Gauss’s central difference formula converged with minimal terms due to balanced difference terms around the central anchor.

#### 7. Conclusion
Newton’s forward and backward formulae and Gauss's central difference method were successfully implemented, yielding accurate interpolated values across disparate regions of the tabular datasets.

---

# Module 4: Least-Squares Curve Fitting

---

### Experiment 4.1: Least-Squares Fitting of a Straight Line

#### 1. Objective
To fit a straight line $Y = a_0 + a_1 X$ to experimental data by minimizing the sum of squared residuals using the method of least squares.

#### 2. Theory
Given $m$ data points $(x_i, y_i)$, the criterion of least squares minimizes the residual sum:
$$S = \sum_{i=1}^m \left[ y_i - (a_0 + a_1 x_i) \right]^2 \tag{4.1}$$
Setting $\frac{\partial S}{\partial a_0} = 0$ and $\frac{\partial S}{\partial a_1} = 0$ yields the normal equations:
$$\begin{aligned} m a_0 + a_1 \sum x &= \sum y \\ a_0 \sum x + a_1 \sum x^2 &= \sum xy \end{aligned} \tag{4.2}$$
Solving this $2 \times 2$ system yields parameters $a_0$ (intercept) and $a_1$ (slope).

#### 3. Algorithm
```text
Algorithm: Linear Least-Squares Fit
Input: Coordinate lists x and y of size m
Output: Intercept a0 and slope a1

1. Accumulate sums: sum_x <- Sum(x), sum_y <- Sum(y)
2. Accumulate cross terms: sum_x2 <- Sum(x_i^2), sum_xy <- Sum(x_i * y_i)
3. Set up matrix system:
     [ m       sum_x  ] [ a0 ] = [ sum_y  ]
     [ sum_x   sum_x2 ] [ a1 ]   [ sum_xy ]
4. Solve system for a0 and a1 via 2x2 determinant inversion
5. Return a0, a1
```

#### 4. Sample Input
| Variable | Point 1 | Point 2 | Point 3 | Point 4 | Point 5 |
| :--- | :---: | :---: | :---: | :---: | :---: |
| $x$ | 1 | 2 | 3 | 4 | 5 |
| $y$ | 0.6 | 2.4 | 3.5 | 4.8 | 5.7 |

- **Number of points:** $m = 5$

#### 5. Output / Results
##### Summary Table of Accumulations:
| $x_i$ | $y_i$ | $x_i^2$ | $x_i y_i$ | Fitted $Y_i$ | Residual $(y_i - Y_i)^2$ |
| :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 0.6 | 1 | 0.6 | 0.8800 | 0.0784 |
| 2 | 2.4 | 4 | 4.8 | 2.1400 | 0.0676 |
| 3 | 3.5 | 9 | 10.5 | 3.4000 | 0.0100 |
| 4 | 4.8 | 16 | 19.2 | 4.6600 | 0.0196 |
| 5 | 5.7 | 25 | 28.5 | 5.9200 | 0.0484 |
| $\sum x = 15$ | $\sum y = 17.0$ | $\sum x^2 = 55$ | $\sum xy = 63.6$ | — | $S = 0.2240$ |

##### System of Normal Equations:
$$\begin{aligned} 5 a_0 + 15 a_1 &= 17.0 \\ 15 a_0 + 55 a_1 &= 63.6 \end{aligned}$$
Solving yields:
$$a_1 = \frac{5(63.6) - 15(17.0)}{5(55) - (15)^2} = \frac{63}{50} = 1.2600$$
$$a_0 = \bar{y} - a_1 \bar{x} = 3.4 - 1.26(3) = -0.3800$$

**Fitted Straight Line:**
$$Y = -0.3800 + 1.2600 X$$

#### 6. Discussion
The residual sum of squares is minimal ($S = 0.2240$), demonstrating strong linear alignment across the dataset. The correlation coefficient is $r \approx 0.993$, verifying a near-ideal linear fit.

#### 7. Conclusion
The least-squares straight-line regression yielded the model $Y = -0.38 + 1.26 X$, successfully characterizing the linear trend of the data.

---

### Experiment 4.2: Least-Squares Fitting of a Second-Degree Parabola

#### 1. Objective
To fit a second-degree polynomial (parabola) $Y = a_0 + a_1 X + a_2 X^2$ to non-linear data points using the principle of least squares.

#### 2. Theory
To capture quadratic curvature, the residual sum of squares is formulated as:
$$S = \sum_{i=1}^m \left[ y_i - (a_0 + a_1 x_i + a_2 x_i^2) \right]^2 \tag{4.3}$$
Minimizing $S$ with respect to $a_0, a_1, a_2$ yields a $3 \times 3$ system of normal equations:
$$\begin{aligned} m a_0 + a_1 \sum x + a_2 \sum x^2 &= \sum y \\ a_0 \sum x + a_1 \sum x^2 + a_2 \sum x^3 &= \sum xy \\ a_0 \sum x^2 + a_1 \sum x^3 + a_2 \sum x^4 &= \sum x^2 y \end{aligned} \tag{4.4}$$

#### 3. Algorithm
```text
Algorithm: Parabolic Least-Squares Regression
Input: Coordinate lists x and y of size m
Output: Coefficients a0, a1, a2

1. Compute sums: sum_x, sum_x2, sum_x3, sum_x4
2. Compute product sums: sum_y, sum_xy, sum_x2y
3. Assemble 3x3 linear system A * [a0, a1, a2]^T = B
4. Solve system using Gaussian elimination or symbolic inversion
5. Return a0, a1, a2
```

#### 4. Sample Input
| Variable | Point 1 | Point 2 | Point 3 | Point 4 | Point 5 |
| :--- | :---: | :---: | :---: | :---: | :---: |
| $x$ | 1 | 2 | 3 | 4 | 5 |
| $y$ | 0.6 | 2.4 | 3.5 | 4.8 | 5.7 |

#### 5. Output / Results
##### Accumulation Table:
| $x$ | $y$ | $x^2$ | $x^3$ | $x^4$ | $xy$ | $x^2y$ |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| 1 | 0.6 | 1 | 1 | 1 | 0.6 | 0.6 |
| 2 | 2.4 | 4 | 8 | 16 | 4.8 | 9.6 |
| 3 | 3.5 | 9 | 27 | 81 | 10.5 | 31.5 |
| 4 | 4.8 | 16 | 64 | 256 | 19.2 | 76.8 |
| 5 | 5.7 | 25 | 125 | 625 | 28.5 | 142.5 |
| $\sum x = 15$ | $\sum y = 17.0$ | $\sum x^2 = 55$ | $\sum x^3 = 225$ | $\sum x^4 = 979$ | $\sum xy = 63.6$ | $\sum x^2y = 288.8$ |

##### Resulting $3 \times 3$ Normal Equations:
$$\begin{aligned} 5 a_0 + 15 a_1 + 55 a_2 &= 17.0 \\ 15 a_0 + 55 a_1 + 225 a_2 &= 63.6 \\ 55 a_0 + 225 a_1 + 979 a_2 &= 288.8 \end{aligned}$$
Solving the system yields:
$$a_0 = -1.1800, \quad a_1 = 1.9457, \quad a_2 = -0.1143$$

**Fitted Parabola:**
$$Y = -1.1800 + 1.9457 X - 0.1143 X^2$$

#### 6. Discussion
The quadratic coefficient $a_2 = -0.1143$ captures a slight downward concavity in the upper range of the data points. The parabolic fit reduces residual variance compared to a purely linear model while maintaining stability against overfitting.

#### 7. Conclusion
The least-squares parabolic fit produced the second-order model $Y = -1.18 + 1.9457 X - 0.1143 X^2$, demonstrating higher adaptability to subtle nonlinear variations.

---

### Experiment 4.3: Nonlinear Curve Fitting via Linearization (Exponential Law)

#### 1. Objective
To fit an exponential growth law $y = a e^{bx}$ to non-linear experimental data points by applying logarithmic transformation and linear regression.

#### 2. Theory
The nonlinear model $y = a e^{bx}$ is non-linear in parameters $a$ and $b$. Taking the natural logarithm of both sides:
$$\ln y = \ln a + bx \tag{4.5}$$
Substituting $Y = \ln y$, $A_0 = \ln a$, $A_1 = b$, and $X = x$, this transforms into the linear equation:
$$Y = A_0 + A_1 X \tag{4.6}$$
Standard linear least-squares normal equations are then constructed and solved for $A_0$ and $A_1$. The original parameter $a$ is recovered via:
$$a = e^{A_0} \tag{4.7}$$

#### 3. Algorithm
```text
Algorithm: Linearized Exponential Curve Fitting
Input: Coordinate lists x and y
Output: Model parameters a and b for y = a * exp(b * x)

1. Compute transformed ordinates: Y_i <- ln(y_i) for all i
2. Accumulate linear least-squares sums for (x_i, Y_i):
     sum_X, sum_Y, sum_X2, sum_XY
3. Solve 2x2 normal equations for A0 and A1
4. Recover original parameters:
     a <- exp(A0)
     b <- A1
5. Return a, b
```

#### 4. Sample Input
| Variable | Point 1 | Point 2 | Point 3 | Point 4 | Point 5 |
| :--- | :---: | :---: | :---: | :---: | :---: |
| $x$ | 1 | 3 | 5 | 7 | 9 |
| $y$ | 2.473 | 6.722 | 18.274 | 49.673 | 135.026 |

- **Number of points:** $m = 5$

#### 5. Output / Results
##### Transformed Variable Table:
| $X = x$ | $y$ | $Y = \ln(y)$ | $X^2$ | $X \cdot Y$ |
| :---: | :---: | :---: | :---: | :---: |
| 1 | 2.473 | 0.90543 | 1 | 0.90543 |
| 3 | 6.722 | 1.90539 | 9 | 5.71616 |
| 5 | 18.274 | 2.90548 | 25 | 14.52740 |
| 7 | 49.673 | 3.90546 | 49 | 27.33823 |
| 9 | 135.026 | 4.90547 | 81 | 44.14921 |
| $\sum X = 25$ | — | $\sum Y = 14.5272$ | $\sum X^2 = 165$ | $\sum XY = 92.6364$ |

##### Transformed Normal Equations:
$$\begin{aligned} 5 A_0 + 25 A_1 &= 14.5272 \\ 25 A_0 + 165 A_1 &= 92.6364 \end{aligned}$$
Solving yields:
$$A_1 = b = \frac{5(92.6364) - 25(14.5272)}{5(165) - 25^2} = \frac{100.002}{200.0} = 0.5000$$
$$A_0 = \bar{Y} - A_1 \bar{X} = 2.90544 - 0.5000(5.0) = 0.4054$$
Recovering $a$:
$$a = e^{A_0} = e^{0.4054} = 1.4999 \approx 1.5000$$

**Fitted Exponential Curve:**
$$y = 1.5000 \, e^{0.5000 \, x}$$

#### 6. Discussion
Linearization transformed the exponential relation into a linear profile. The recovered parameters ($a \approx 1.5000, b \approx 0.5000$) demonstrate exact exponential progression, as $e^{0.5000 \times 2} = e^1 \approx 2.718$ represents the exact growth factor every 2 units of $x$.

#### 7. Conclusion
The nonlinear exponential model was successfully linearized and fitted using the least-squares criterion, producing the model $y = 1.50 e^{0.50 x}$.
