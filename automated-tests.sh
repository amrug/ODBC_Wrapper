#!/usr/bin/env bash

# run unit tests
./bin/test_hello

if [ $? -ne 0 ]; then
 echo “unit tests failed”
 exit 1
fi

# static code analysis
# cppcheck ...
# Parasoft C/C++test
# if [ $? -ne 0 ]; then
 # echo “static code analysis failed”
 # exit 1
#fi
