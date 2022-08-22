#ifndef ODBC_DATABASE_H
#define ODBC_DATABASE_H

#pragma once

#include <memory>
#include <iostream>
#include "IPrintableDatabase.h"
#include "IDatabasePrinter.h"
#include "ISQLDatabase.h"


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

class ODBC_Database : public ISQLDatabase, IPrintableDatabase
{
public:
  ODBC_Database(std::string cs) {}

  std::shared_ptr<IDatabasePrinter> createPrinter(PRINTER_STYLE printerStyle);

  void execute_sql(const std::string sql_query);

  void printLastStatement(PRINTER_STYLE printerStyle = PRINTER_STYLE_CSV,
                          std::ostream &os = std::cout);
};

#endif