cmake_minimum_required(VERSION 3.0.0)

add_executable(
  main
  main.cpp
  )

target_link_libraries(
  main
  ODBC_Wrapper
  odbc
)

add_subdirectory(libODBC_Wrapper)
