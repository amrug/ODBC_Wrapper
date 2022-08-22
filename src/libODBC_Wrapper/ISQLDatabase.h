#ifndef ISQLDATABASE_H
#define ISQLDATABASE_H

#pragma once

#include <string>

class ISQLDatabase
{
public:
  virtual void execute_sql(std::string sql_query) = 0;
};

#endif