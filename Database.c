#include "Database.h"
#include "DBConfig.h"

MYSQL_ROW getAccountData(char name[100], int code){

    MYSQL *conn;
    conn = mysql_init(NULL);
    if(!mysql_real_connect(conn, host, user, pass, dbname, port, unix_socket, flag)){
        fprintf(stderr, "\nError: %s[%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }

    char query[100];
    char query2[100];

    snprintf(query, 100, "SELECT * FROM accounts WHERE name='%s';", name);

    mysql_query(conn, query);
    MYSQL_RES* res = mysql_store_result(conn);
    if(mysql_num_rows(res) == 0){
        char* message[] = {"invalid_user"};
        char** s = message;
        return s;
    }
    mysql_free_result(res);

    snprintf(query2, 100, "SELECT * FROM accounts WHERE name='%s' AND code='%d';", name, code);
    mysql_query(conn, query2);
    res = mysql_store_result(conn);
    MYSQL_ROW row = mysql_fetch_row(res);
    if(mysql_num_rows(res) == 0){
        char* message[] = {"invalid_code"};
        char** s = message;
        return s;
    }
    mysql_free_result(res);
    return row;
}

void updateBalance(char* n, int a){
    MYSQL *conn;
    conn = mysql_init(NULL);
    if(!mysql_real_connect(conn, host, user, pass, dbname, port, unix_socket, flag)){
        fprintf(stderr, "\nError: %s[%d]\n", mysql_error(conn), mysql_errno(conn));
        exit(1);
    }

    char query[100];

    snprintf(query, 100, "UPDATE `accounts` SET `balance`=balance-%d WHERE name='%s'", a, n);
    mysql_query(conn, query);
}