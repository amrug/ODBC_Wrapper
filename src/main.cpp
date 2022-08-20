//
// https://www.easysoft.com/developer/languages/c/odbc_tutorial.html
//
#include "ODBC_Database_Wrapper.h"
#include "ODBC_Database_Wrapper_Printer.h"

int main() {
  auto db = std::make_shared<ODBC_Database_Wrapper>("DSN=ODBC;");
  ODBC_Database_Wrapper_CsvPrinter csvPrinter;
  ODBC_Database_Wrapper_Printer normalPrinter;

  db->execute("DROP TABLE employee;");
  db->execute("CREATE TABLE employee (user_id serial PRIMARY KEY, \
                                      username VARCHAR ( 50 ) UNIQUE NOT NULL, \
                                      email VARCHAR ( 50 ), \
                                      salary real);");
  db->execute("INSERT INTO employee (username, salary) VALUES ('Hello Wordl!', 1999.65);");
  db->execute("INSERT INTO employee (username, email, salary) VALUES ('A. P.', 'a@programer.com', 2999.65);");
  db->execute("INSERT INTO employee (username, salary) VALUES ('Hugo', 2499.65);");


  db->execute("SELECT * FROM employee");
  normalPrinter.print(db);

  db->execute("SELECT * FROM employee");
  csvPrinter.print(db);

  db->execute("SELECT username, salary FROM employee ORDER BY salary DESC LIMIT 2");
  csvPrinter.print(db);
}
