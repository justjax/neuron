cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)

project(Neuron)

add_executable(${PROJECT_NAME} "main.cpp" "DatasetParser.cpp")

