#include "ODBC_Database_Wrapper.h"

void extract_error(
    char *fn,
    SQLHANDLE handle,
    SQLSMALLINT type)
{
    SQLINTEGER   i = 0;
    SQLINTEGER   native;
    SQLCHAR      state[ 7 ];
    SQLCHAR      text[256];
    SQLSMALLINT  len;
    SQLRETURN    ret;

    fprintf(stderr,
            "\n"
            "The driver reported the following diagnostics whilst running "
            "%s\n\n",
            fn);

    do
    {
        ret = SQLGetDiagRec(type, handle, ++i, state, &native, text,
                            sizeof(text), &len );
        if (SQL_SUCCEEDED(ret))
            printf("%s:%d:%d:%s\n", state, i, native, text);
    }
    while( ret == SQL_SUCCESS );
}



void ODBC_Database_Wrapper::execute(std::string sql_query) {
  SQLFreeHandle(SQL_HANDLE_STMT, stmt);
  SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
  ret = SQLExecDirect(stmt, (unsigned char*)sql_query.c_str(), sql_query.size());
  SQLNumResultCols(stmt, &columns);
}

ODBC_Database_Wrapper::ODBC_Database_Wrapper(std::string connection) {
  /* Allocate an environment handle */
  SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
  /* We want ODBC 3 support */
  SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *) SQL_OV_ODBC3, 0);
  /* Allocate a connection handle */
  SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
  /* Connect to the DSN ODBC */
  ret = SQLDriverConnect(dbc, NULL, (unsigned char*)"DSN=ODBC;", SQL_NTS,
                         outstr, sizeof(outstr), &outstrlen,
                         SQL_DRIVER_COMPLETE);


  SQLAllocStmt(dbc, &stmt);

  if (SQL_SUCCEEDED(ret)) {
    printf("Connected\n");
    // printf("Returned connection string was:\n\t%s\n", outstr);
    if (ret == SQL_SUCCESS_WITH_INFO) {
      printf("Driver reported the following diagnostics\n");
      extract_error((char*)"SQLDriverConnect", dbc, SQL_HANDLE_DBC);
    }
    // std::cout << "=================" << std::endl;
  }
}


ODBC_Database_Wrapper::~ODBC_Database_Wrapper() {
  /* free up allocated handles */
  SQLFreeHandle(SQL_HANDLE_STMT, stmt);
  SQLDisconnect(dbc);
  SQLFreeHandle(SQL_HANDLE_DBC, dbc);
  SQLFreeHandle(SQL_HANDLE_ENV, env);
}
