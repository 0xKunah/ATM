#ifndef ATM_ACCOUNT_H
#define ATM_ACCOUNT_H

    #include "Database.h"

    bool login();

    void logout();

    char* getName();

    int balance();

    bool withdraw(int amount);

#endif //ATM_ACCOUNT_H
