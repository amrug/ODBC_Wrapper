#ifndef ABS_SQL_DATABASE_H_
#define ABS_SQL_DATABASE_H_

#include <string>
#include <pqxx/pqxx>

class ABS_SQL_Database {
  public:
    ABS_SQL_Database() = default;
    virtual void connect(std::string c) = 0;
    virtual pqxx::result execute(std::string query) = 0;
    virtual ~ABS_SQL_Database() = default;
  private:
};

#endif // ABS_SQL_DATABASE_H_
