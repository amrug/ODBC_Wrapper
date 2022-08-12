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

