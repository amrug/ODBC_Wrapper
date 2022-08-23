#include "ODBC_Database.hpp"

#include <exception>
#include <sstream>
#include "ODBC_NORMAL_Printer.hpp"
#include "ODBC_CSV_Printer.hpp"


NS_ODBC_WRAPPER_START

void ODBC_Database::extract_error(
    char *fn,
    SQLHANDLE handle,
    SQLSMALLINT type)
{
    SQLINTEGER i = 0;
    SQLINTEGER native;
    SQLCHAR state[7];
    SQLCHAR text[256];
    SQLSMALLINT len;
    SQLRETURN ret;

    fprintf(stderr,
            "\n"
            "The driver reported the following diagnostics whilst running "
            "%s\n\n",
            fn);

    do
    {
        ret = SQLGetDiagRec(type, handle, ++i, state, &native, text,
                            sizeof(text), &len);
        if (SQL_SUCCEEDED(ret))
            printf("%s:%d:%d:%s\n", state, i, native, text);
    } while (ret == SQL_SUCCESS);
}

void ODBC_Database::connect(std::string connection)
{
    /* Allocate an environment handle */
    ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env);
    if (!SQL_SUCCEEDED(ret))
    {
        std::stringstream ss;
        ss << "SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &env) failed:" << std::endl
           << "\tret: " << ret << std::endl;
        throw std::runtime_error(ss.str());
    }

    /* We want ODBC 3 support */
    ret = SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0);
    if (!SQL_SUCCEEDED(ret))
    {
        std::stringstream ss;
        ss << "SQLSetEnvAttr(env, SQL_ATTR_ODBC_VERSION, (void *)SQL_OV_ODBC3, 0) failed:" << std::endl
           << "\tret: " << ret << std::endl;
        throw std::runtime_error(ss.str());
    }

    /* Allocate a connection handle */
    ret = SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc);
    if (!SQL_SUCCEEDED(ret))
    {
        std::stringstream ss;
        ss << "SQLAllocHandle(SQL_HANDLE_DBC, env, &dbc) failed: " << std::endl
           << "\tenv: " << env << std::endl
           << "\tret: " << ret << std::endl;
        throw std::runtime_error(ss.str());
    }

    /* Connect to the DSN ODBC */
    ret = SQLDriverConnect(dbc, NULL, (unsigned char *)connection.c_str(), SQL_NTS,
                           outstr, sizeof(outstr), &outstrlen,
                           SQL_DRIVER_COMPLETE);

    if (SQL_SUCCEEDED(ret))
    {
        // printf("Returned connection string was:\n\t%s\n", outstr);
        if (ret == SQL_SUCCESS_WITH_INFO)
        {
            printf("Driver reported the following diagnostics\n");
            extract_error((char *)"SQLDriverConnect", dbc, SQL_HANDLE_DBC);
        }
        // std::cout << "=================" << std::endl;
    }
    else
    {
        std::stringstream ss;
        ss << "SQLDriverConnect failed in file:\n"
           << __FILE__ << ", line: " << __LINE__ << std::endl
           << "\tconnection: " << connection << std::endl
           << "\toutstr: " << outstr << std::endl
           << "\tret: " << ret << std::endl;
        throw std::runtime_error(ss.str());
    }
}

ODBC_Database::ODBC_Database(std::string connection)
{
    connect(connection);
}

void ODBC_Database::print_last_sql_statement(PRINTER_STYLE printerStyle, std::ostream &os)
{
    createPrinter(printerStyle)->print(os);
};

void ODBC_Database::execute_sql(const std::string sql_query)
{
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
    SQLAllocHandle(SQL_HANDLE_STMT, dbc, &stmt);
    ret = SQLExecDirect(stmt, (unsigned char *)sql_query.c_str(), sql_query.size());
    if (!SQL_SUCCEEDED(ret))
    {
        throw std::runtime_error("Execute SQL_Query failed:\n\t" + sql_query);
    }
    SQLNumResultCols(stmt, &columns);
}

ODBC_Database::~ODBC_Database()
{
    SQLFreeHandle(SQL_HANDLE_STMT, stmt);
    SQLDisconnect(dbc);
    SQLFreeHandle(SQL_HANDLE_DBC, dbc);
    SQLFreeHandle(SQL_HANDLE_ENV, env);
}

std::shared_ptr<IDatabasePrinter> ODBC_Database::createPrinter(PRINTER_STYLE printerStyle)
{
    switch (printerStyle)
    {
    case PRINTER_STYLE_NORMAL:
        return std::make_shared<ODBC_NORMAL_Printer>(stmt, columns);

    case PRINTER_STYLE_CSV:
        return std::make_shared<ODBC_CSV_Printer>(stmt, columns);
    default:
        std::stringstream ss;
        ss << "createPrinter Failed: " << std::endl
           << "PRINTER_STYLE: " << printerStyle << "doesn't exists!" << std::endl;
        throw std::runtime_error(ss.str());
    }
};

NS_ODBC_WRAPPER_END