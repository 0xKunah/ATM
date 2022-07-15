#include "Account.h"

char name[100];
int code;
char** account_data;

bool login(){
    if(strcmp(name, "") == 0){
        printf("Votre nom: \n>");
        scanf("%s", name);
    }
    printf("Code du compte %s: \n>", name);
    scanf("%d", &code);
    account_data = getAccountData(name, code);
    if(strcmp(account_data[0], "invalid_user") == 0){
        printf("Utilisateur invalide.\n");
        strcpy(name, "");
        login();
    } else if (strcmp(account_data[0], "invalid_code") == 0) {
        printf("Code invaliide, réessayez.\n");
        login();
    } else return true;
}

void updateAccountData(){
    account_data = getAccountData(name, code);
}

void logout(){
    strcpy(name, "");
    code = 0;
    strcpy(account_data[0], "");
    strcpy(account_data[1], "");
    strcpy(account_data[2], "");
}

bool withdraw(int amount){
    updateBalance(name, amount);
    updateAccountData();
}

char* getName(){
    return account_data[1];
}

int balance(){
    return strtol(account_data[2], NULL, 10);
}