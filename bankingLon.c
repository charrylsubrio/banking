#include <stdio.h>
#include <string.h>

float acceptAmount();
float computeDepBalance(float, float);
float computeWithBalance(float, float);
float computeInt(float);
void displayClientRec(int, char name[], char address[], float);

int main() {
    int accNum, choice;
    char name[50];
    char address[50];
    float balance = 0;
    
    printf("Enter your Account Number: ");
    scanf("%d", &accNum);
    fflush(stdin);
	printf("Enter your Name: ");
    gets(name);
    fflush(stdin);
	printf("Enter your Address: ");
    gets(address);
    
    system("cls");
    
	do {
        printf("\nMAIN MENU\n\n");
        printf("[1] Deposit\n");
        printf("[2] Withdraw\n");
        printf("[3] Display Client Record\n");
        printf("[4] Compute Interest\n");
        printf("[5] Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                balance = computeDepBalance(balance, acceptAmount());
                break;
            case 2:
                balance = computeWithBalance(balance, acceptAmount());
                break;
            case 3:
                displayClientRec(accNum, name, address, balance);
                break;
            case 4:
                printf("Annual Interest: %.2f\n", computeInt(balance));
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 5.\n");
        }
    } while (choice != 5);

    return 0;
}


float acceptAmount() {
    float amount;
    printf("Enter amount: ");
    scanf("%f", &amount);
    return amount;
}


float computeDepBalance(float balance, float amount) {
    if (amount < 100.00) {
        printf("\nDeposit amount should not be below 100.00.\n");
        return balance;
    }
    return balance + amount;
}


float computeWithBalance(float balance, float amount) {
    if (balance - amount < 500.00) {
        printf("\nWithdrawal amount makes the balance below 500.00. Withdrawal not allowed.\n");
        return balance;
    }
    return balance - amount;
}


float computeInt(float balance) {
    return balance * 0.03; 
}


void displayClientRec(int accNum, char name[], char address[], float balance) {
    printf("\nClient Record:\n");
    printf("Account Number: %d\n", accNum);
    printf("Name: %s\n", name);
    printf("Address: %s\n", address);
    printf("Balance: %.2f\n", balance);
}