cmake_minimum_required(VERSION 3.0.0)
project(helloworld VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
# set(CMAKE_BUILD_TYPE Release)
# set(CMAKE_BUILD_TYPE Debug)
add_definitions(-DCMAKE_EXPORT_COMPILE_COMMANDS=ON)

include_directories(${CMAKE_SOURCE_DIR}/src/libODBC_Wrapper)

add_subdirectory(src)
# add_subdirectory(tests)
