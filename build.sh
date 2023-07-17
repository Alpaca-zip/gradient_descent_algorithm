#!/bin/bash
# Tested on Ubuntu-20.04
# Tested on Ubuntu-22.04

if [ ! -d "matplotlib-cpp" ]; then
  echo "matplotlib-cpp not found, cloning from GitHub..."
  git clone https://github.com/lava/matplotlib-cpp.git
fi

cmake -S . -B build
cmake --build build
cd ./build/
mv gradient_descent ../gradient_descent.out
