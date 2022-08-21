#include "ODBC_Database_Wrapper_Printer.h"
#include "ODBC_Database_Wrapper.h"

#include <string.h>

void ODBC_Database_Wrapper_CsvPrinter::print(std::shared_ptr<ODBC_Database_Wrapper> db, std::ostream& os) {
    const char separator    = ' ';
    const int nameWidth     = 25;
    const int numWidth      = 8;

    //if (auto db = dynamic_cast<ODBC_Database_Wrapper*>(db.get()))
    {
        // do Child specific stuff
        while (SQL_SUCCEEDED(db->ret = SQLFetch(db->stmt))) {
            // printf("\nRow %d\n", db->row++);
            for (int i = 1; i <= db->columns; i++) {
                SQLLEN indicator;
                char buf[512];
                db->ret = SQLGetData(db->stmt, i, SQL_C_CHAR,
                                     buf, sizeof(buf), &indicator);
                if (SQL_SUCCEEDED(db->ret)) {
                    if (indicator == SQL_NULL_DATA) strcpy(buf, "NULL");
                    os << (i>1?"; ":"") << std::left << std::setw(nameWidth) << std::setfill(separator) << buf;
                }
            }
            os << "\n";
        }
        os << "\n";
    }
};


void ODBC_Database_Wrapper_Printer::print(std::shared_ptr<ODBC_Database_Wrapper> db, std::ostream& os) {
    // if (auto db = dynamic_cast<ODBC_Database_Wrapper*>(db.get()))
    {
        // do Child specific stuff
        while (SQL_SUCCEEDED(db->ret = SQLFetch(db->stmt))) {
            os << "\nRow " << db->row++ << "\n";
            // printf("\nRow %d\n", db->row++);
            for (int i = 1; i <= db->columns; i++) {
                SQLLEN indicator;
                char buf[512];
                db->ret = SQLGetData(db->stmt, i, SQL_C_CHAR,
                                     buf, sizeof(buf), &indicator);
                if (SQL_SUCCEEDED(db->ret)) {
                    if (indicator == SQL_NULL_DATA) strcpy(buf, "NULL");
                    os << "  Column " << i << " : " << buf << "\n";
                }
            }
        }
        os << "\n";
    }
};
