#ifndef ODBC_DATABASE_WRAPPER_PRINTER_H_
#define ODBC_DATABASE_WRAPPER_PRINTER_H_

#include <memory>
#include <iostream>

class ODBC_Database_Wrapper;

class ABC_ODBC_Database_Wrapper_Printer {
  public:
    virtual void print(std::shared_ptr<ODBC_Database_Wrapper> db, std::ostream& os) = 0;
};

class ODBC_Database_Wrapper_CsvPrinter : public ABC_ODBC_Database_Wrapper_Printer {
  public:
    ODBC_Database_Wrapper_CsvPrinter() = default;
    void print(std::shared_ptr<ODBC_Database_Wrapper> db, std::ostream& os = std::cout) override ;
};

class ODBC_Database_Wrapper_Printer : public ABC_ODBC_Database_Wrapper_Printer {
  public:
    ODBC_Database_Wrapper_Printer() = default;
    void print(std::shared_ptr<ODBC_Database_Wrapper> db, std::ostream& os = std::cout) override;
};


#endif // ODBC_DATABASE_WRAPPER_PRINTER_H_
