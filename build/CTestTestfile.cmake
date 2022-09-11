# CMake generated Testfile for 
# Source directory: /home/user/list_project
# Build directory: /home/user/list_project/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(tests "/home/user/list_project/build/tests")
set_tests_properties(tests PROPERTIES  _BACKTRACE_TRIPLES "/home/user/list_project/CMakeLists.txt;20;add_test;/home/user/list_project/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
