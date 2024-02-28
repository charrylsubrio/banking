#include <stdio.h>
#include <string.h>

float balance;

//required functions:
int acceptAccNum(void);
float acceptAmount(void);
float computeDepBalance(float, float);
float computeWithBalance(float, float);
float computeInt(float);
void displayClientRec(int, char[], char[], float);

//add-on functions:


int main() {
	int accNum, choice;
	char cName[50], cAdd[50];
	float depAmount, withAmount, interest;
	
	accNum = acceptAccNum();
	fflush(stdin);
	
	printf("Input Your Name: ");
	gets(cName);
	fflush(stdin);
	
	printf("Input Your Address: ");
	gets(cAdd);
	
	do {
		printf("Input Initial Deposit: ");
		scanf("%f", &balance);
		
		if(balance < 500) {
			printf("\nPlease deposit atleast 500.00\n\n");
		}
	} while (balance < 500);
	
	do {
		do {
			printf("\n[1] Deposit");
			printf("\n[2] Withdraw");
			printf("\n[3] Display Client Record");
			printf("\n[4] Compute Interest");
			printf("\n[0] Exit\n\n");
			printf("Input choice: ");
			
			scanf("%d", &choice);
			
			if(choice < 0 || choice > 4) {
				printf("\nInvalid option!\n");
			}
		} while(choice < 0 || choice > 4);
		
		switch(choice) {
			case 1:
				do {
					depAmount = acceptAmount();
					
					if(depAmount < 100) {
						printf("\nPlease deposit atleast 100.00\n");
					}
				} while (depAmount < 100);
				
				balance = computeDepBalance(balance, depAmount);
				break;
			case 2:
				if(balance <= 500) {
					printf("\nYou can't withdraw with only balance of 500.00\n");
					break;		
				} else {
					do {	
						do {
							withAmount = acceptAmount();
							if(withAmount <= 0) {
						    	printf("\nPlease withdraw atleast 1.00\n"); 
							}
						} while(withAmount <= 0);
						
						if(balance - withAmount < 500) {
							printf("\nPlease maintain account balance atleast 500.00\n");
						}
					} while(balance - withAmount < 500);
				}
				balance = computeWithBalance(balance, withAmount);
				break;
			case 3:
				displayClientRec(accNum, cName, cAdd, balance);
				break;
			case 4:
				interest = computeInt(balance);
				printf("\nInterest: %.2f\n", interest);
		}		
	} while(choice != 0);
	
	return 0;
}

int acceptAccNum(void) {
	int accNum;
	
	printf("Input Your Account Number: ");
	scanf("%d", &accNum);
	
	return accNum;
}

float acceptAmount(void) {
    float amount;
    
    printf("\nEnter Amount: ");
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
    printf("\nAccount Number: %d\n", accNum);
    printf("Name: %s\n", cName);
    printf("Address: %s\n", cAdd);
    printf("Balance: %.2f\n", balance);
}