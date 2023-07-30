/*
  Copyright 2023 Alapaca-zip

  Licensed under the Apache License, Version 2.0 (the "License");
  you may not use this file except in compliance with the License.
  You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

  Unless required by applicable law or agreed to in writing, software
  distributed under the License is distributed on an "AS IS" BASIS,
  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
  See the License for the specific language governing permissions and
  limitations under the License.
*/

#include "gradient_descent_node.hpp"

void GradientDescentNode::userInput()
{
  try {
    std::cout << "Objective function" << std::endl;
    _x1_mat = getInputVector(" Enter the order matrix of x1: ");
    _x2_mat = getInputVector(" Enter the order matrix of x2: ");
    _coeff_mat = getInputVector(" Enter the order matrix of coefficient: ");
    checkSizeAndDisplayFunction(_x1_mat, _x2_mat, _coeff_mat, "=> f(x1, x2) = ", "");

    std::cout << "\n";
    std::cout << "====================" << std::endl;
    std::cout << "Gradient vector" << std::endl;
    std::cout << "x1-component of the gradient" << std::endl;
    _gradx1_x1_mat = getInputVector(" Enter the order matrix of x1: ");
    _gradx1_x2_mat = getInputVector(" Enter the order matrix of x2: ");
    _gradx1_coeff_mat = getInputVector(" Enter the order matrix of coefficient: ");

    std::cout << "x2-component of the gradient" << std::endl;
    _gradx2_x1_mat = getInputVector(" Enter the order matrix of x1: ");
    _gradx2_x2_mat = getInputVector(" Enter the order matrix of x2: ");
    _gradx2_coeff_mat = getInputVector(" Enter the order matrix of coefficient: ");
    checkSizeAndDisplayFunction(_gradx1_x1_mat, _gradx1_x2_mat, _gradx1_coeff_mat, "=> [", "");
    checkSizeAndDisplayFunction(_gradx2_x1_mat, _gradx2_x2_mat, _gradx2_coeff_mat, ", ", "]");

    std::cout << "\n";
    std::cout << "====================" << std::endl;
    std::cout << "Enter the starting point (x1, x2): ";
    std::cin >> _x_start >> _y_start;

  } catch (const std::invalid_argument & e) {
    std::cerr << e.what() << std::endl;
    std::exit(EXIT_FAILURE);
  }
}

std::vector<int> GradientDescentNode::getInputVector(const std::string & prompt)
{
  int input;
  std::string line;
  std::vector<int> result;
  std::cout << prompt;
  std::getline(std::cin, line);
  std::istringstream stream(line);
  while (stream >> input) {
    result.push_back(input);
  }
  return result;
}

void GradientDescentNode::checkSizeAndDisplayFunction(
  const std::vector<int> & x1, const std::vector<int> & x2, const std::vector<int> & coeff,
  const std::string & start, const std::string & end)
{
  if (x1.size() != x2.size() || x1.size() != coeff.size()) {
    throw std::invalid_argument("Sizes of the input matrices do not match.");
  } else {
    displayFunction(x1, x2, coeff, start, end);
  }
}

void GradientDescentNode::displayFunction(
  const std::vector<int> & x1, const std::vector<int> & x2, const std::vector<int> & coeff,
  const std::string & start, const std::string & end)
{
  std::cout << start;
  for (size_t i = 0; i < coeff.size(); ++i) {
    if (coeff[i] != 0) {
      if (i != 0) {
        if (coeff[i] > 0) {
          std::cout << " + ";
        } else {
          std::cout << " ";
        }
      }
      std::cout << coeff[i];
      if (x1[i] != 0 || x2[i] != 0) {
        if (x1[i] != 0) {
          std::cout << "*x1";
          if (x1[i] != 1) {
            std::cout << "^" << x1[i];
          }
        }
        if (x2[i] != 0) {
          std::cout << "*x2";
          if (x2[i] != 1) {
            std::cout << "^" << x2[i];
          }
        }
      }
    }
  }
  std::cout << end;
}

void GradientDescentNode::solveGradientDescent()
{
  auto start_time = std::chrono::high_resolution_clock::now();
  const int max_iter = 10000;
  const double precision = 1e-4;
  const double xi = 0.3;
  const double tau = 0.9;
  std::cout << "\n";
  std::cout << "Default values:" << std::endl;
  std::cout << " max_iter = " << max_iter << std::endl;
  std::cout << " precision = " << precision << std::endl;
  std::cout << " xi = " << xi << std::endl;
  std::cout << " tau = " << tau << std::endl;
  std::cout << "If these values are not suitable, please modify them in the code." << std::endl;
  std::cout << "\n";

  double alpha;
  std::vector<double> x_curr, x_next;
  std::vector<double> grad_curr;
  x_curr = {_x_start, _y_start};

  for (int i = 0; i < max_iter; i++) {
    auto elapsed_time = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - start_time).count();
    alpha = 1.0;
    grad_curr = calcGradient(x_curr[0], x_curr[1]);
    _path.push_back({x_curr[0], x_curr[1]});
    std::cout << "====================" << std::endl;
    std::cout << "Iteration: " << i + 1 << std::endl;
    std::cout << " Current x1 and x2 values = [" << x_curr[0] << ", " << x_curr[1] << "]" << std::endl;
    std::cout << " Objective Function Value = " << calcObjective(x_curr[0], x_curr[1]) << std::endl;
    std::cout << " Gradient = [" << grad_curr[0] << ", " << grad_curr[1] << "]" << std::endl;
    std::cout << " Gradient Norm = " << norm(grad_curr[0], grad_curr[1]) << std::endl;
    std::cout << " Elapsed Time = " << elapsed_time << " ms" << std::endl;

    if (norm(grad_curr[0], grad_curr[1]) < precision) {
      break;
    }

    while (true) {
      x_next = {x_curr[0] - alpha * grad_curr[0], x_curr[1] - alpha * grad_curr[1]};

      if (
        calcObjective(x_next[0], x_next[1]) <=
        calcObjective(x_curr[0], x_curr[1]) - xi * alpha * dot(grad_curr, grad_curr)) {
        x_curr = x_next;
        break;
      }
      alpha *= tau;
    }

    if (i == max_iter - 1) {
      std::cout
        << "Warning: Maximum number of epochs reached without convergence to the desired precision."
        << std::endl;
    }
  }
}

std::vector<double> GradientDescentNode::calcGradient(const double x, const double y)
{
  std::vector<double> grad(2);

  for (int i = 0; i < _gradx1_coeff_mat.size(); i++) {
    grad[0] +=
      _gradx1_coeff_mat[i] * std::pow(x, _gradx1_x1_mat[i]) * std::pow(y, _gradx1_x2_mat[i]);
    grad[1] +=
      _gradx2_coeff_mat[i] * std::pow(x, _gradx2_x1_mat[i]) * std::pow(y, _gradx2_x2_mat[i]);
  }

  return grad;
}

double GradientDescentNode::calcObjective(const double x, const double y)
{
  double obj = 0.0;

  for (int i = 0; i < _coeff_mat.size(); i++) {
    obj += _coeff_mat[i] * std::pow(x, _x1_mat[i]) * std::pow(y, _x2_mat[i]);
  }

  return obj;
}

double GradientDescentNode::norm(const double x, const double y)
{
  return std::sqrt(x * x + y * y);
}

double GradientDescentNode::dot(const std::vector<double> & a, const std::vector<double> & b)
{
  double dot_product = 0.0;

  for (int i = 0; i < a.size(); i++) {
    dot_product += a[i] * b[i];
  }

  return dot_product;
}

void GradientDescentNode::plotFunctionAndPath()
{
  int num_level = 10;
  int num_points = 100;
  double min_x1 = std::numeric_limits<double>::max();
  double max_x1 = std::numeric_limits<double>::min();
  double min_x2 = std::numeric_limits<double>::max();
  double max_x2 = std::numeric_limits<double>::min();

  for (const auto & point : _path) {
    min_x1 = std::min(min_x1, point[0]);
    max_x1 = std::max(max_x1, point[0]);
    min_x2 = std::min(min_x2, point[1]);
    max_x2 = std::max(max_x2, point[1]);
  }

  double range_x1 = max_x1 - min_x1;
  double range_x2 = max_x2 - min_x2;
  double range_max = std::max(range_x1, range_x2);
  double center_x1 = (min_x1 + max_x1) / 2.0;
  double center_x2 = (min_x2 + max_x2) / 2.0;

  min_x1 = center_x1 - range_max / 2.0 - range_max * 0.3;
  max_x1 = center_x1 + range_max / 2.0 + range_max * 0.3;
  min_x2 = center_x2 - range_max / 2.0 - range_max * 0.3;
  max_x2 = center_x2 + range_max / 2.0 + range_max * 0.3;

  std::vector<std::vector<double>> x1_vals, x2_vals, z_vals;
  std::vector<double> path_x1, path_x2;

  for (double x1 = min_x1; x1 <= max_x1; x1 += range_x1 / num_points) {
    std::vector<double> x1_row, x2_row, z_row;
    for (double x2 = min_x2; x2 <= max_x2; x2 += range_x2 / num_points) {
      double z = calcObjective(x1, x2);
      x1_row.push_back(x1);
      x2_row.push_back(x2);
      z_row.push_back(z);
    }
    x1_vals.push_back(x1_row);
    x2_vals.push_back(x2_row);
    z_vals.push_back(z_row);
  }

  for (int i = 0; i < _path.size(); i++) {
    path_x1.push_back(_path[i][0]);
    path_x2.push_back(_path[i][1]);
  }

  plt::figure();
  plt::contour(x1_vals, x2_vals, z_vals);
  plt::plot(path_x1, path_x2, "-o");
  plt::title("Result of Gradient Descent");
  plt::xlim(min_x1, max_x1);
  plt::ylim(min_x2, max_x2);
  plt::show();
}

int main(int argc, char ** argv)
{
  GradientDescentNode GDN;
  GDN.userInput();
  GDN.solveGradientDescent();
  GDN.plotFunctionAndPath();
  return 0;
}
