# gradient_descent_algorithm  [![Ubuntu-latest Build Check](https://github.com/Alpaca-zip/gradient_descent_algorithm/actions/workflows/build-check-bot.yml/badge.svg?event=push)](https://github.com/Alpaca-zip/gradient_descent_algorithm/actions/workflows/build-check-bot.yml)
This repository contains an implementation of the Gradient Descent Algorithm in C++, utilizing the Armijo condition to optimize step sizes.

## How to Use

### 1. Clone this repository.
```
$ git clone https://github.com/Alpaca-zip/gradient_descent_algorithm.git
```
### 2. Install dependencies and compile the program.
```
$ python3 -m pip install matplotlib numpy
$ build.sh
```
### 3. Run the program. 
1. Upon running the program, you need to input the objective function as vectors for two variables (x1, x2), each defined by their degree and coefficient. You're asked to enter the order matrices for x1, x2, and the coefficient respectively.
2. Then, you define the gradient vector similar to the objective function, with two components, each being a function of x1 and x2.
3. Next, you provide an initial pair of numbers (x1, x2) as the starting point for gradient descent.

**Example**

$$
f(x_{1}, x_{2}) = 2x_{1}^2+x_{2}^2+x_{1}x_{2}
$$

$$
\nabla f(x_{1}, x_{2}) = [4x_{1}+x_{2}, x_{1}+2x_{2}]^T
$$
```
$ run.sh
Objective function
 Enter the order matrix of x1: 2 0 1
 Enter the order matrix of x2: 0 2 1
 Enter the order matrix of coefficient: 2 1 1
=> f(x1, x2) = 2*x1^2 + 1*x2^2 + 1*x1*x2
====================
Gradient vector
x1-component of the gradient
 Enter the order matrix of x1: 1 0
 Enter the order matrix of x2: 0 1
 Enter the order matrix of coefficient: 4 1
x2-component of the gradient
 Enter the order matrix of x1: 1 0
 Enter the order matrix of x2: 0 1
 Enter the order matrix of coefficient: 1 2
=> [4*x1 + 1*x2, 1*x1 + 2*x2]
====================
Enter the starting point (x1, x2): 1.5 1.5

Default values:
 max_iter = 10000
 precision = 0.0001
 xi = 0.3
 tau = 0.9
If these values are not suitable, please modify them in the code.

====================
Iteration: 1
 x_curr = [1.5, 1.5]
 grad_curr = [7.5, 4.5]
====================
Iteration: 2
 x_curr = [-0.853579, 0.0878523]
 grad_curr = [-3.32647, -0.677875]
====================
...
```
### 4. The results will be displayed as figure.
Finally, the program outputs the contour and the path of the gradient descent as plots. You can modify parameters like max iterations, precision, step size in the code itself.

<img src="https://github.com/Alpaca-zip/dijkstra_algorithm/assets/84959376/e33b595b-f3d9-4204-aa60-29cc5580e4a5" width="600px">
