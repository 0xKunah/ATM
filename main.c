#include "Account.h"

void outline(){
    printf("-------------------------------\n");
}

void interface(){
    char* n = getName();
    outline();
    printf("Connecté en tant que %s\nQuelle opération souhaitez vous effectuer ?\nRetrait (1)\nConsulter votre solde (2)\nDéconnexion (3)\n", n);
    int choice;
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            int amount;
            printf("Quel montant souhaitez vous retirer ?\n>");
            scanf("%d", &amount);
            if(amount > balance()){
                printf("Vous ne possédez pas cette somme.\n");
            } else withdraw(amount);
            break;
        case 2:
            outline();
            printf("Votre solde actuel est de: %d€\n", balance());
            break;
        case 3:
            logout();
            return;
        default:
            printf("Opération invalide, réessayez.\n");
            break;
    }
    interface();
}

int main(){
    bool is_logged = login();
    if(is_logged){
        interface();
    }
}

