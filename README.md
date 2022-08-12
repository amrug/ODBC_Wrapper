# Minimal example to set up a C++ project with CMake and gtest

$ tree
<br>├── bin/
<br>├── build/
<br>├── CMakeLists.txt
<br>├── lib/
<br>├── README.md
<br>├── src/
<br>│   ├── CMakeLists.txt
<br>│   ├── libmymath/
<br>│   │   ├── CMakeLists.txt
<br>│   │   ├── mymath.cpp
<br>│   │   └── mymath.h
<br>│   └── main.cpp
<br>└── tests/
<br>     ├── CMakeLists.txt
<br>     └── test_hello.cpp

## Build instructions:

cd build 

cmake ..

make -j


## Automate Unit Tests before each commit by Git Hooks

https://blog.devgenius.io/automate-unit-tests-before-each-commit-by-git-hook-f331f0499786

https://medium.com/@yagizcemberci/automate-unit-tests-with-git-hooks-e25e8b564c92

## vscode

### Add the following line to c_cpp_properties.json for debugging:

"compileCommands": "${workspaceFolder}/build/compile_commands.json",

### Auto generate c_cpp_properties.json:

Press STRG+SHIFT+p

and select C/C++: Edit Configurations (JSON)
