
#include"myBank.c"
#define MATRIX_LENGTH   50
#define VALUES_IN_ACCOUNT 2

void openingBankAccount( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]);
void accountBalance( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]);
void Deposit(double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]);
void Withdrawal( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]);
void closure( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]);
void updateInterest( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]);
void printAll(  double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]);
void end( double matrixBank[MATRIX_LENGTH][VALUES_IN_ACCOUNT]);