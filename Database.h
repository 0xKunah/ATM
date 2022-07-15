#ifndef ATM_FILECONTROLLER_H
#define ATM_FILECONTROLLER_H

    #include <stdbool.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <mysql/mysql.h>

    MYSQL_ROW getAccountData(char name[100], int code);

    void updateBalance(char* n, int a);

#endif //ATM_FILECONTROLLER_H
