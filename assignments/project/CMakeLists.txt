cmake_minimum_required(VERSION 3.14)

# Change "projectName" to whatever you want
set(this projectName)

# Defines the project and the language we are using
project(${this} CXX)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

# Allows us to include the Google Test framework
add_subdirectory(googletest)
add_subdirectory(eigen)

# Change foo.h and huh.h to the headers in your project
# Do not delete "Headers"; this is the name of a variable
set(Headers
    hamming_code.h
)

# Change foo.cpp and huh.cpp to the headers in your project
# Do not delete "Sources"; this is the name of a variable
# Make sure to not include a main function in any of these files
set(Sources
    hamming_code.cpp
)

set(EIGEN3_INCLUDE_DIRS
    "eigen/Eigen/"
)

set(DataFiles
    "./hamming_code.txt"
    "./invalid_codewordlength.txt"
)

# Find and include the Eigen library
find_package(Eigen3 REQUIRED)

# Creates a library from the source code we provided in "Sources" and "Headers"
add_library(${this} SHARED ${Sources} ${Headers} ${DataFiles})
target_include_directories(${this} PUBLIC ${EIGEN3_INCLUDE_DIRS})  # Use PRIVATE instead of PUBLIC

# Sets the name of the testing executable we are creating
# You can rename "testingExample" to whatever you want
set(test testingExample)

# Change test.cpp to the name of your testing file
# Your testing file should not include a main file
set(testSources
    test.cpp
)

# Creates the testing executable and links it to our project and
# the Google Test framework
add_executable(${test} ${testSources})
target_link_libraries(${test} PUBLIC
    gtest_main # when testing, gtest provides the main function
    ${this}
)

# Allows us to use ctest
add_test(
    NAME ${test}
    COMMAND ${test}
)
