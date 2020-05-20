# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("sc")

set(BOOST_ROOT "E:/boost_1_73_0")
include_directories(${BOOST_ROOT})
# Include sub-projects.
add_subdirectory ("sc")