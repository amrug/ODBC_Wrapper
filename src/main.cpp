//
// https://www.easysoft.com/developer/languages/c/odbc_tutorial.html
//
#include "ODBC_Database.h"

int main()
{
  auto db = std::make_shared<ODBC_Database>("DSN=ODBC;");

  db->execute_sql("DROP TABLE employee;");
  db->execute_sql("CREATE TABLE employee (user_id serial PRIMARY KEY, \
                                      username VARCHAR ( 50 ) UNIQUE NOT NULL, \
                                      email VARCHAR ( 50 ), \
                                      salary real);");
  db->execute_sql("INSERT INTO employee (username, salary) VALUES ('Hello Wordl!', 1999.65);");
  db->execute_sql("INSERT INTO employee (username, email, salary) VALUES ('A. P.', 'a@programer.com', 2999.65);");
  db->execute_sql("INSERT INTO employee (username, salary) VALUES ('Hugo', 2499.65);");

  db->execute_sql("SELECT * FROM employee");
  db->print_last_sql_statement(PRINTER_STYLE_NORMAL, std::cout);

  db->execute_sql("SELECT * FROM employee");
  db->print_last_sql_statement(PRINTER_STYLE_CSV, std::cout);

  db->execute_sql("SELECT username, salary FROM employee ORDER BY salary DESC LIMIT 2");
  db->print_last_sql_statement(PRINTER_STYLE_CSV, std::cout);
}
