#ifndef ODBC_NORMAL_PRINTER_H
#define ODBC_NORMAL_PRINTER_H

#pragma once

#include "Config.hpp"
#include "IDatabasePrinter.hpp"
#include <iostream>

#include <sql.h>
#include <sqlext.h>
#include <iomanip>
#include <string.h>
#include <memory>

NS_ODBC_WRAPPER_START

class ODBC_Database;

class ODBC_NORMAL_Printer : public IDatabasePrinter
{
public:
  ODBC_NORMAL_Printer(SQLHSTMT &stmt, SQLSMALLINT columns);

  void print(std::ostream &os = std::cout) override;

private:
  SQLHSTMT &m_stmt;
  SQLSMALLINT m_columns;
};


NS_ODBC_WRAPPER_END

#endif