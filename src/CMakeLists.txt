cmake_minimum_required(VERSION 2.4)

add_executable(main main.cpp)

target_link_libraries(
  main
  mymath
)

add_subdirectory(libmymath)
