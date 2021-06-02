#include <stdio.h>
#define MATRIX_LENGTH   50
#define VALUES_IN_ACCOUNT 2
#define FIRST_ACCOUNT 901


static int interest=1;


int chose(int x){
    if (x == EOF) return -1;
     if (x == 1) return 0;
    return -2;
}


int setAccount_number( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]){
    printf("Please enter account number: ");
    int account_number;
    int x = chose(scanf("%d", &account_number));
    if(x==-1) return -1;
    if (x==-2){
        printf("Failed to read the account number\n"); 
        return -1;
        } 

    account_number-=FIRST_ACCOUNT;
    if (account_number < 0) printf("Invalid account number\n");
    else if(account_number >= MATRIX_LENGTH) printf("Invalid account number\n"); 
    else if (matrixBank[account_number][0] == 0) return-2;
    // printf("This account is closed\n");
    else return account_number; 
    return -1;
}


void openingBankAccount(double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]){
    int newAccount = -1;
    for (int i = 0; i < MATRIX_LENGTH && newAccount == -1; i++){
        if (matrixBank[i][0] == 0)
            newAccount = i;
            }
        if (newAccount == -1) printf("Error! the bank is full \n");
        else{
            printf("Please enter amount for deposit: ");
            double amount;
            int x = chose(scanf("%lf", &amount));
            if (x == -1) return;
            if (x == -2){
                printf("Failed to read the amount\n");
                return;
                }
            if (amount < 0) printf("Invalid Amount\n");
            else{
                printf("New account number is: %d \n", FIRST_ACCOUNT + newAccount);
                matrixBank[newAccount][1] = amount;
                matrixBank[newAccount][0] = 1;
                }
            }
}


void accountBalance( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]){
    int account_number= setAccount_number(matrixBank);
    if(account_number==-2){
        printf("This account is closed\n"); 
        return;  
    }
   
    if (account_number==-1) return;
    printf("The balance of account number %d is: %0.2lf\n",FIRST_ACCOUNT+account_number,matrixBank[account_number][1]*interest);
}


void Deposit( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]){
    int account_number = setAccount_number(matrixBank);
    if(account_number==-2){
        printf("This account is closed\n"); 
        return;  
    }
    if (account_number == -1) return;
    printf("Please enter the amount to deposit: ");
    double amount;
    int x=chose(scanf("%lf", &amount));
    if (x==-1) return;
    else if(x==-2){
        printf("Failed to read the amount\n");
        return;
    }
    if (amount < 0){
        printf("Cannot deposit a negative amount\n");
        return;
    }
    matrixBank[account_number][1] += amount;
    printf("The new balance is: %0.2lf\n", matrixBank[account_number][1] * interest);
}


void Withdrawal( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]){
    int account_number = setAccount_number(matrixBank);
    if(account_number==-2){
        printf("This account is closed\n"); 
        return;  
    }
    if (account_number == -1) return;
    printf("Please enter the amount to withdraw: ");
    double amount_withdraw;
    int x=chose(scanf("%lf", &amount_withdraw));
    if (x==-1) return;
    if (x==-2){
        printf("Invalid withdrawal amount\n");
        return;
        }
    if (matrixBank[account_number][1] < amount_withdraw){
        printf("Cannot withdraw more than the balance\n");
        return;
        }
    matrixBank[account_number][1] -= amount_withdraw;
    printf("The new balance is: %0.2lf\n", matrixBank[account_number][1]* interest);
}



void closure( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]){
   int account_number = setAccount_number(matrixBank);
   if(account_number==-2){
       printf("This account is already closed\n");
        return;  
    }
    if (account_number == -1) return;
    // if (matrixBank[account_number][0] == 0){
    //     printf("This account is already closed\n");
    //     return;
    //     }
    matrixBank[account_number][0] = 0;
    printf("Closed account number %d\n",account_number+901);
}



void updateInterest( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]){
    printf("Please enter interest rate: ");
    int percentageIncrease;
    int x=chose(scanf("%d", &percentageIncrease));
    if (x==-1) return;
    if (x==-2){
        printf("Failed to read the interest rate\n");
        return;
        }
    if (percentageIncrease < 0){
        printf("Invalid interest rate\n");
        return;
        }
    for (int i = 0; i < MATRIX_LENGTH; i++){
        if (matrixBank[i][0]==1){
            matrixBank[i][1]*=(percentageIncrease / 100.0)+1; 
        }
    }
    
}




void printAll( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]){

    for (int i =0 ; i < MATRIX_LENGTH; i++){
        if (matrixBank[i][0]==1){
            printf("The balance of account number %d is: %0.2lf\n",i+FIRST_ACCOUNT,matrixBank[i][1]);
        }
    }
}


void end( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]){
    for (int i = 0; i < MATRIX_LENGTH; i++){
        matrixBank[i][0]=0;
    }
}

