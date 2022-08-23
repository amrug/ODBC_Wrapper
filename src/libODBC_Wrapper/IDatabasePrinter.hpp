#ifndef IDATABASEPRINTER_H
#define IDATABASEPRINTER_H

#pragma once

#include <ostream>
#include "Config.hpp"

NS_ODBC_WRAPPER_START

class IDatabasePrinter
{
public:
  virtual void print(std::ostream &os) = 0;
};

NS_ODBC_WRAPPER_END

#endif