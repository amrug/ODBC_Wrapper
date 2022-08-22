# This is a C++ Wrapper for ODBC-Databases.

## Install ODBC-driver for your database. In case of PostgreSQL and Debian Linux:

`apt install unixodbc-dev odbc-postgresql`


`cat /etc/odbcinst.ini `

```
[PostgreSQL ANSI]
Description=PostgreSQL ODBC driver (ANSI version)
Driver=psqlodbca.so
Setup=libodbcpsqlS.so
Debug=0
CommLog=1
UsageCount=1

[PostgreSQL Unicode]
Description=PostgreSQL ODBC driver (Unicode version)
Driver=psqlodbcw.so
Setup=libodbcpsqlS.so
Debug=0
CommLog=1
UsageCount=1
```

`cat ~/.odbc.ini`

```
[ODBC]
Driver = PostgreSQL ANSI
Server = localhost,5432
Protocol = 8.4
UserName = postgres
Password = mypassword
Database = test
```
