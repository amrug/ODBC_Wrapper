#ifndef ODBC_CSV_PRINTER_H
#define ODBC_CSV_PRINTER_H

#pragma once


#include "IDatabasePrinter.h"
#include <iostream>

class ODBC_CSV_Printer : public IDatabasePrinter
{
public:
  void print(std::ostream &os = std::cout) override;
};


#endif