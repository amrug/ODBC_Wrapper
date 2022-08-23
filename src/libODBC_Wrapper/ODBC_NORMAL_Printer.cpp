#include "ODBC_NORMAL_Printer.hpp"

#include "ODBC_Database.hpp"

ODBC_NORMAL_Printer::ODBC_NORMAL_Printer(SQLHSTMT& stmt,
                                         SQLSMALLINT columns)
    : m_stmt(stmt), m_columns(columns)
{
}

void ODBC_NORMAL_Printer::print(std::ostream &os)
{
  SQLRETURN ret; /* ODBC API return status */
  int row=0;
  while (SQL_SUCCEEDED(SQLFetch(m_stmt)))
  {
    os << "\nRow " << row++ << "\n";
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
        os << "  Column " << i << " : " << buf << "\n";
      }
    }
  }
  os << "\n";
}