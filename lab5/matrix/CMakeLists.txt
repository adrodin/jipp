# cmake version to be used
cmake_minimum_required( VERSION 3.0 )

# project name
project(matrix VERSION 1.0.0)

# flags

# files

# include
include_directories( ./include ./src )

# target
add_executable(${PROJECT_NAME} ./src/main.cpp ./src/matrix.cpp)




