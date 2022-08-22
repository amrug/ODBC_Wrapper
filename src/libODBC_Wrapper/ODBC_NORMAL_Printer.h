#ifndef ODBC_NORMAL_PRINTER_H
#define ODBC_NORMAL_PRINTER_H

#pragma once

#include "IDatabasePrinter.h"

#include <iostream>

class ODBC_NORMAL_Printer : public IDatabasePrinter
{
public:

  void print(std::ostream &os = std::cout) override;

};


#endif