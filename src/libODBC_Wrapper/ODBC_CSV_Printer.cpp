#include "ODBC_CSV_Printer.hpp"

#include "ODBC_Database.hpp"


NS_ODBC_WRAPPER_START

ODBC_CSV_Printer::ODBC_CSV_Printer(SQLHSTMT &stmt,
                                   SQLSMALLINT columns)
    : m_stmt(stmt), m_columns(columns)
{
}

void ODBC_CSV_Printer::print(std::ostream &os)
{
  const char separator = ' ';
  const int nameWidth = 25;
  const int numWidth = 8;
  SQLRETURN ret; /* ODBC API return status */
  int row = 0;

  // do Child specific stuff
  while (SQL_SUCCEEDED(ret = SQLFetch(m_stmt)))
  {
    // printf("\nRow %d\n", db->row++);
    for (int i = 1; i <= m_columns; i++)
    {
      SQLLEN indicator;
      char buf[512];
      ret = SQLGetData(m_stmt, i, SQL_C_CHAR,
                       buf, sizeof(buf), &indicator);
      if (SQL_SUCCEEDED(ret))
      {
        if (indicator == SQL_NULL_DATA)
          strcpy(buf, "NULL");
        os << (i > 1 ? "; " : "") << std::left << std::setw(nameWidth) << std::setfill(separator) << buf;
      }
    }
    os << "\n";
  }
  os << "\n";
}


NS_ODBC_WRAPPER_END