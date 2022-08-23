#ifndef ODBC_DATABASE_H
#define ODBC_DATABASE_H

#pragma once

#include <memory>
#include <iostream>
#include "IPrintableDatabase.hpp"
#include "IDatabasePrinter.hpp"
#include "ISQLDatabase.hpp"

#include <sql.h>
#include <sqlext.h>
#include <iomanip>

/**                        Factory Pattern
 *                        =================
 *
 * IDatabasePrinter                          IPrintableDatabase
 *          ^                                         ^
 *          |                                         |
 *          |                                         |
 *  ODBC_CSV_Printer   <---------------------- ODBC_Database
 *  ODBC_NORMAL_Printer
 */

class ODBC_Database : public ISQLDatabase,
                      IPrintableDatabase
{
public:
  ODBC_Database() = delete;
  ODBC_Database(std::string connection);
  ~ODBC_Database();

  void execute_sql(const std::string sql_query);

  void print_last_sql_statement(PRINTER_STYLE printerStyle = PRINTER_STYLE_CSV,
                          std::ostream &os = std::cout);

private:
  void extract_error(char *fn, SQLHANDLE handle, SQLSMALLINT type);
  std::shared_ptr<IDatabasePrinter> createPrinter(PRINTER_STYLE printerStyle);
  void connect(std::string connection) override;

private:
  SQLHENV env;
  SQLHDBC dbc;
  SQLHSTMT stmt;
  SQLRETURN ret; /* ODBC API return status */
  SQLCHAR outstr[1024];
  SQLSMALLINT outstrlen;
  SQLSMALLINT columns = 3;
  int row = 0;
};

#endif