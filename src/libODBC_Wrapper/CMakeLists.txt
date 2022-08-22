cmake_minimum_required(VERSION 3.9)
project(ODBC_Wrapper VERSION 0.0.1 DESCRIPTION "ODBC_Wrapper")

add_library(${PROJECT_NAME} SHARED
  ODBC_Database.cpp
  ODBC_CSV_Printer.cpp
  ODBC_NORMAL_Printer.cpp
)
