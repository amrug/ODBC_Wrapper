#ifndef IDATABASEPRINTER_H
#define IDATABASEPRINTER_H

#pragma once

#include <ostream>

class IDatabasePrinter
{
public:
  virtual void print(std::ostream &os) = 0;
};

#endif