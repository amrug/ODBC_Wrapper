# Minimal example to set up a C++ project with CMake and gtest

$ tree

├── bin/

├── build/

├── CMakeLists.txt

├── lib/

├── README.md

├── src/

│   ├── CMakeLists.txt

│   ├── libmymath/

│   │   ├── CMakeLists.txt

│   │   ├── mymath.cpp

│   │   └── mymath.h

│   └── main.cpp

└── tests/

├── CMakeLists.txt

└── test_hello.cpp

## Build instructions:

cd build 

cmake ..

make -j

