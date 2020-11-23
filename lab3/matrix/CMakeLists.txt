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





#add_library(randomize STATIC IMPORTED)
#set_property(TARGET randomize PROPERTY IMPORTED_LOCATION ${CMAKE_SOURCE_DIR}/libs/Randomize/librandomize.a)
#target_link_libraries( binary randomize )