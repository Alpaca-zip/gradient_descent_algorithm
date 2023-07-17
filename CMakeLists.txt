cmake_minimum_required(VERSION 3.0.2)
project(gradient_descent)

find_package(PythonLibs REQUIRED)

# Setting the include paths
include_directories(${PYTHON_INCLUDE_DIRS})
include_directories(include)

# Setting up the executable
add_executable(gradient_descent src/gradient_descent_node.cpp)

# Linking the libraries
target_link_libraries(gradient_descent ${PYTHON_LIBRARIES})
