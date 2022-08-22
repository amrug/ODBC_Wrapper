#include "ODBC_Database.h"

#include <exception>
#include <sstream>
#include "ODBC_NORMAL_Printer.h"
#include "ODBC_CSV_Printer.h"


void ODBC_Database::printLastStatement(PRINTER_STYLE printerStyle, std::ostream &os)
{
    std::cout << "ODBC_Database print: " << printerStyle << std::endl;
    createPrinter(printerStyle)->print(os);
};

void ODBC_Database::execute_sql(const std::string sql_query)
{
    std::cout << sql_query << std::endl;
}

std::shared_ptr<IDatabasePrinter> ODBC_Database::createPrinter(PRINTER_STYLE printerStyle)
{
#pragma message(": warning<return other Printers>: ")
    switch (printerStyle)
    {
    case PRINTER_STYLE_NORMAL:
        return std::make_shared<ODBC_NORMAL_Printer>();
    case PRINTER_STYLE_CSV:
        return std::make_shared<ODBC_CSV_Printer>();
    default:
        std::stringstream ss;
        ss << "createPrinter Failed: " << std::endl
           << "PRINTER_STYLE: " << printerStyle << "doesn't exists!" << std::endl;
        throw std::runtime_error(ss.str());
    }
};

// ODBC_Database::ODBC_Database()
// {

// }

// ODBC_Database::~ODBC_Database()
// {

// }