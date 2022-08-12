cmake_minimum_required(VERSION 3.9)
project(mymath VERSION 0.0.1 DESCRIPTION "mylib description")

add_library(${PROJECT_NAME} SHARED
  mymath.cpp
)
