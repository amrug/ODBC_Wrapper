#ifndef ODBC_CSV_PRINTER_H
#define ODBC_CSV_PRINTER_H

#pragma once

#include "IDatabasePrinter.h"
#include <iostream>

#include <sql.h>
#include <sqlext.h>
#include <iomanip>
#include <string.h>
#include <memory>

class ODBC_Database;

class ODBC_CSV_Printer : public IDatabasePrinter
{
public:
  ODBC_CSV_Printer(SQLHSTMT &stmt, SQLSMALLINT columns);

  void print(std::ostream &os = std::cout) override;

private:
  SQLHSTMT &m_stmt;
  SQLSMALLINT m_columns;
};

#endif