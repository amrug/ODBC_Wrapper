#ifndef ISQLDATABASE_H
#define ISQLDATABASE_H

#pragma once

#include <string>

#include "Config.hpp"
NS_ODBC_WRAPPER_START

class ISQLDatabase
{
public:
  virtual void execute_sql(std::string sql_query) = 0;
  virtual void connect(std::string connection) = 0;
};

NS_ODBC_WRAPPER_END

#endif