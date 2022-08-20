#ifndef ODBC_DATABASE_WRAPPER_H_
#define ODBC_DATABASE_WRAPPER_H_

#include <stdio.h>
#include <sql.h>
#include <string.h>
#include <sqlext.h>
#include <iostream>
#include <memory>
#include <iomanip>

void extract_error(char *fn, SQLHANDLE handle, SQLSMALLINT type);


class AAA_ODBC_Database_Wrapper_Manager {
  public:
    AAA_ODBC_Database_Wrapper_Manager();
    virtual void connect();
    virtual void execute(std::string sql_query);
    virtual ~AAA_ODBC_Database_Wrapper_Manager();
};

class ABC_ODBC_Database_Wrapper {
  protected:
    SQLHENV env;
    SQLHDBC dbc;
    SQLHSTMT stmt;
    SQLRETURN ret; /* ODBC API return status */
    SQLCHAR outstr[1024];
    SQLSMALLINT outstrlen;
    SQLSMALLINT columns = 3;
    int row = 0;

  public:
    virtual void execute(std::string sql_query) {

    };
};


class ODBC_Database_Wrapper : public ABC_ODBC_Database_Wrapper  {
  public:
    ODBC_Database_Wrapper() = delete;
    ODBC_Database_Wrapper(std::string connection);
    void execute(std::string sql_query);
    virtual ~ODBC_Database_Wrapper();
    // friend class ABC_ODBC_Database_Wrapper_Printer;
    friend class ODBC_Database_Wrapper_Printer;
    friend class ODBC_Database_Wrapper_CsvPrinter;
};


#endif // ODBC_DATABASE_WRAPPER_H_
