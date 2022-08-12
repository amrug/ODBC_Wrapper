cmake_minimum_required(VERSION 2.4)

add_executable(main main.cpp)

target_link_libraries(
  main
  mymath
)
add_subdirectory(libmymath)

# cmake .
# clear ; make && ./main

# mkdir debug ; cd debug ; cmake -DCMAKE_BUILD_TYPE=Debug ..
# mkdir release ; cd release ; cmake -DCMAKE_BUILD_TYPE=Release ..
# clear ; make && ./main
