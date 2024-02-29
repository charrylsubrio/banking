#include <stdio.h>
#include <string.h>
#include <conio.h>

float balance;

//required functions:
int acceptAccNum(void);
float acceptAmount(void);
float computeDepBalance(float, float);
float computeWithBalance(float, float);
float computeInt(float);
void displayClientRec(int, char[], char[], float);

//add-on functions:
float acceptInitialDep(void);

int main() {
	int accNum, choice;
	char clientName, cName[50], cAdd[50];
	float depAmount, withAmount, interest;
	
	printf("BANKING APP\n\n");
	printf("OPEN NEW ACCOUNT\n\n");
	
	accNum = acceptAccNum();
	
	printf("Input Client Name     : ");
	gets(cName);
	fflush(stdin);
	
	printf("Input Client Address  : ");
	gets(cAdd);
	
	balance = acceptInitialDep();
	
	do {
		do {
			printf("BANKING APP\n\n");
			printf("MAIN MENU\n\n");
			printf("[1] - Deposit");
			printf("\n[2] - Withdraw");
			printf("\n[3] - Display Client's Record");
			printf("\n[4] - Compute Interest");
			printf("\n[0] - Exit\n\n");
			printf("Input choice: ");
			
			scanf("%d", &choice);
			
			if(choice < 0 || choice > 4) {
				printf("\n- Invalid. Please input from 0 to 4\n\n");
				printf("Press any key to continue: ... ");
				getch();
				system("cls");
			}
			
			if(choice == 2 && balance == 500) {
				printf("\n- The account balance should not be below 500.00\n");
				printf("- Current Balance: %.2f\n", balance);
				printf("\nPress any key to continue ... ");
				getch();
				system("cls");
			} else {
				system("cls");
			}
		} while(choice < 0 || choice > 4);
		
		switch(choice) {
			case 1:
				do {
					printf("BANKING APP\n\n");
					printf("DEPOSIT\n\n");
					
					depAmount = acceptAmount();
					
					if(depAmount < 100) {
						printf("\n- Invalid. The deposit amount should be at least 100.00\n\n");
						printf("Press any key to continue ... ");
						getch();
						system("cls");
					}
				} while (depAmount < 100);
				
				balance = computeDepBalance(balance, depAmount);
				printf("\n- Deposit Successful!\n");
				printf("- New Balance: %.2f\n", balance);
				printf("\nPress any key to continue ... ");
				getch();
				system("cls");
				break;
			case 2:
				if(balance == 500) {
					break;		
				} else {
					do {	
						do {
							printf("BANKING APP\n\n");
							printf("WITHDRAW\n\n");
							withAmount = acceptAmount();
							if(withAmount <= 0) {
						    	printf("\n- Invalid. Please withdraw at least 1.00\n\n");
								printf("Press any key to continue ... ");
								getch();
								system("cls"); 
							}
						} while(withAmount <= 0);
						
						if(balance - withAmount < 500) {
							printf("\n- Invalid. The account balance should not be below 500.00\n");
							printf("- Current Balance: %.2f\n\n", balance);
							printf("Press any key to continue ... ");
							getch();
							system("cls"); 
						}
					} while(balance - withAmount < 500);
				}
				balance = computeWithBalance(balance, withAmount);
				printf("\n- Withdraw Successful!\n");
				printf("- New Balance: %.2f\n", balance);
				printf("\nPress any key to continue ... ");
				getch();
				system("cls");
				break;
			case 3:
				printf("BANKING APP\n\n");
				printf("CLIENT'S RECORD\n");
				displayClientRec(accNum, cName, cAdd, balance);
				printf("\nPress any key to continue ... ");
				getch();
				system("cls");
				break;
			case 4:
				printf("BANKING APP\n\n");
				printf("INTEREST\n\n");
				interest = computeInt(balance);
				printf("- Account Balance\t: %.2f\n", balance);
				printf("- Interest Rate\t\t: 3%%\n\n");
				printf("- Annual Interest\t: %.2f\n", interest);
				printf("\nPress any key to continue ... ");
				getch();
				system("cls");
				break;
		}		
	} while(choice != 0);
	
	return 0;
}

int acceptAccNum(void) {
	int accNum;
	
	printf("Input Account Number  : ");
	scanf("%d", &accNum);
	fflush(stdin);
	
	return accNum;
}

float acceptAmount(void) {
    float amount;
    
    printf("Enter Amount: ");
    scanf("%f", &amount);
    
    return amount;
}

float computeDepBalance(float balance, float depAmount) {
    
    return balance + depAmount;
}

float computeWithBalance(float balance, float withAmount) {
    
    return balance - withAmount;
}

float computeInt(float balance) {
    
    return balance * 0.03;
}

void displayClientRec(int accNum, char cName[], char cAdd[], float balance) {
    printf("\n1. Account Number\t: %d\n", accNum);
    printf("2. Client Name\t\t: %s\n", cName);
    printf("3. Client Address\t: %s\n", cAdd);
    printf("4. Account Balance\t: %.2f\n", balance);
}

float acceptInitialDep(void) {
	do {
		printf("Input Initial Deposit : ");
		scanf("%f", &balance);
		
		if(balance < 500) {
			printf("\n- Invalid. Please enter an amount of at least 500.00\n\n");
		}
	} while (balance < 500);
	
	system("cls");
	
	return balance;
}