#include <stdio.h>
#include "myBank.h"

#define NUMBER_OF_ACCOUNTS 50
#define VALUES_IN_ACCOUNT 2

int main(){
    double matrixBank[NUMBER_OF_ACCOUNTS][VALUES_IN_ACCOUNT] = {0};
    char transactionType;
    while (transactionType != 'E')
    {

        printf("\n");
        printf("Please choose a transaction type:\n");
        printf(" O-Open Account\n");
        printf(" B-Balance Inquiry\n");
        printf(" D-Deposit\n");
        printf(" W-Withdrawal\n");
        printf(" C-Close Account\n");
        printf(" I-Interest\n");
        printf(" P-Print\n");
        printf(" E-Exit\n");







        int InputTester = chose(scanf("%c", &transactionType));
        if (InputTester == -1) return 0;
        else if (InputTester == -2){
            printf("Invalid transaction type\n");
            break;
        }
        if (transactionType == '\n' || transactionType == ' '){
            scanf("%c", &transactionType);
        }

        switch (transactionType){
        case 'O':
            openingBankAccount(matrixBank);
            break;

        case 'B':
            accountBalance(matrixBank);
            break;

        case 'D':
            Deposit(matrixBank);
            break;

        case 'W':
            Withdrawal(matrixBank);
            break;

        case 'C':
            closure(matrixBank);
            break;

        case 'I':
            updateInterest(matrixBank);
            break;

        case 'P':
            printAll(matrixBank);
            break;

        case 'E':
            end(matrixBank);
            break;

        default:
            printf("Invalid transaction type\n");
            break;
        }
    }

    return 0;
}