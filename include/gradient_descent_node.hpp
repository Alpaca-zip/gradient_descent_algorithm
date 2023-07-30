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

#pragma once

#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>

#include "../matplotlib-cpp/matplotlibcpp.h"

namespace plt = matplotlibcpp;

class GradientDescentNode
{
private:
  double _x_start, _y_start;
  std::vector<int> _x1_mat, _x2_mat, _coeff_mat, _gradx1_x1_mat, _gradx1_x2_mat, _gradx1_coeff_mat,
    _gradx2_x1_mat, _gradx2_x2_mat, _gradx2_coeff_mat;
  std::vector<std::vector<double>> _path;

public:
  void userInput();
  std::vector<int> getInputVector(const std::string & prompt);
  void checkSizeAndDisplayFunction(
    const std::vector<int> & x1, const std::vector<int> & x2, const std::vector<int> & coeff,
    const std::string & start, const std::string & end);
  void displayFunction(
    const std::vector<int> & x1, const std::vector<int> & x2, const std::vector<int> & coeff,
    const std::string & start, const std::string & end);
  void solveGradientDescent();
  std::vector<double> calcGradient(const double x, const double y);
  double calcObjective(const double x, const double y);
  double norm(const double x, const double y);
  double dot(const std::vector<double> & a, const std::vector<double> & b);
  void plotFunctionAndPath();
};
