#ifndef IPRINTABLEDATABASE_H
#define IPRINTABLEDATABASE_H

#pragma once

#include <memory>

#include "Config.hpp"
NS_ODBC_WRAPPER_START

class IDatabasePrinter;

enum PRINTER_STYLE
{
    PRINTER_STYLE_NORMAL,
    PRINTER_STYLE_CSV
};

class IPrintableDatabase
{
public:
    virtual std::shared_ptr<IDatabasePrinter> createPrinter(PRINTER_STYLE printerStyle) = 0;
    virtual void print_last_sql_statement(PRINTER_STYLE printerStyle, std::ostream &os) = 0;
};

NS_ODBC_WRAPPER_END

#endif