#ifndef ODBC_DATABASE_WRAPPER_H_
#define ODBC_DATABASE_WRAPPER_H_

#include <stdio.h>
#include <sql.h>
#include <string.h>
#include <sqlext.h>
#include <iostream>
#include <memory>
#include <iomanip>

class ODBC_Database_Wrapper {
  private:
    SQLHENV env;
    SQLHDBC dbc;
    SQLHSTMT stmt;
    SQLRETURN ret; /* ODBC API return status */
    SQLCHAR outstr[1024];
    SQLSMALLINT outstrlen;
    SQLSMALLINT columns = 3;
    int row = 0;
  public:
    ODBC_Database_Wrapper() = delete;
    ODBC_Database_Wrapper(std::string connection);
    void execute(std::string sql_query);
    void extract_error(char *fn, SQLHANDLE handle, SQLSMALLINT type);
    virtual ~ODBC_Database_Wrapper();
    // friend class ABC_ODBC_Database_Wrapper_Printer;
    friend class ODBC_Database_Wrapper_Printer;
    friend class ODBC_Database_Wrapper_CsvPrinter;
};


#endif // ODBC_DATABASE_WRAPPER_H_
