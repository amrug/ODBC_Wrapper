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


## vscode

### Add the following line to c_cpp_properties.json for debugging:

"compileCommands": "${workspaceFolder}/build/compile_commands.json",

### Auto generate c_cpp_properties.json:

Press STRG+SHIFT+p

and select C/C++: Edit Configurations (JSON)
