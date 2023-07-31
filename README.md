# gradient_descent_algorithm  [![Ubuntu-latest Build Check](https://github.com/Alpaca-zip/gradient_descent_algorithm/actions/workflows/build-check-bot.yml/badge.svg?event=push)](https://github.com/Alpaca-zip/gradient_descent_algorithm/actions/workflows/build-check-bot.yml)
This repository contains an implementation of the Gradient Descent Algorithm in C++, utilizing the Armijo condition to optimize step sizes.

## How to Use

### 1. Clone this repository.
```
$ git clone https://github.com/Alpaca-zip/gradient_descent_algorithm.git
```
### 2. Install dependencies and compile the program.
```
$ sudo apt-get install -y python3-matplotlib python3-numpy python3-dev
$ bash build.sh
```
### 3. Run the program. 
1. Upon running the program, you need to input the objective function as vectors for two variables $(x_{1}, x_{2})$, each defined by their degree and coefficient. You're asked to enter the order matrices for $x_{1}$, $x_{2}$, and the coefficient respectively.
2. Then, you define the gradient vector similar to the objective function, with two components, each being a function of x1 and x2.
3. Next, you provide an initial pair of numbers $(x_{1}, x_{2})$ as the starting point for gradient descent.

**Example**

$$
f(x_{1}, x_{2}) = 2x_{1}^2+x_{2}^2+x_{1}x_{2}
$$

$$
\nabla f(x_{1}, x_{2}) = [4x_{1}+x_{2}, x_{1}+2x_{2}]^T
$$
```
$ bash run.sh
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
 max_iter = 100000
 precision = 0.0001
 xi = 0.0001
 tau = 0.5
If these values are not suitable, please modify them in the code.

====================
Iteration: 1
 Current x1 and x2 values = [1.5, 1.5]
 Objective Function Value = 9
 Gradient = [7.5, 4.5]
 Gradient Norm = 8.74643
 Elapsed Time = 277 microseconds
====================
Iteration: 2
 Current x1 and x2 values = [-0.375, 0.375]
 Objective Function Value = 0.28125
 Gradient = [-1.125, 0.375]
 Gradient Norm = 1.18585
 Elapsed Time = 587 microseconds
====================
...
```
### 4. The results will be displayed as figure.
Finally, the program outputs the contour and the path of the gradient descent as plots. You can modify parameters like max iterations, precision, step size in the code itself.

<img src="https://github.com/Alpaca-zip/gradient_descent_algorithm/assets/84959376/1bde4e46-b624-4155-a275-eefdd537be40" width="600px">
