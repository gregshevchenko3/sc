# CMakeList.txt : CMake project for sc, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (sc "sc.cpp" "math_operations.cpp"  "parsers.cpp")

# TODO: Add tests and install targets if needed.
