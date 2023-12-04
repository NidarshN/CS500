# CMake generated Testfile for 
# Source directory: /Users/nidarsh/Code/Masters/CPP/assignments/project
# Build directory: /Users/nidarsh/Code/Masters/CPP/assignments/project/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(testingExample "/Users/nidarsh/Code/Masters/CPP/assignments/project/build/testingExample")
set_tests_properties(testingExample PROPERTIES  _BACKTRACE_TRIPLES "/Users/nidarsh/Code/Masters/CPP/assignments/project/CMakeLists.txt;67;add_test;/Users/nidarsh/Code/Masters/CPP/assignments/project/CMakeLists.txt;0;")
subdirs("googletest")
subdirs("eigen")
