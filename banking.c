#include <stdio.h>
#include <string.h>

float balance;

//required functions:
int acceptAccNum(void);
float acceptAmount(void);
float computeDepBalance(float, float);
float computeWithBalance(float, float);
float computeInt(float);
void displayClientRec(int, char, char, float);

//add-on functions:


int main() {
	int accNum;
	char cName[50], cAdd[50];
	float depAmount, withAmount;
	
	accNum = acceptAccNum();
	fflush(stdin);
	
	printf("Input Your Name: ");
	gets(cName);
	fflush(stdin);
	
	printf("Input Your Address: ");
	gets(cAdd);
	
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
    
    printf("Enter Amount: ");
    scanf("%f", &amount);
    
    return amount;
}

float computeDepBalance(float balance, float depAmount) {
    
    return balance + depAmount;
}

float computeWithBalance(float balance, float withAmount) {
    
    return balance + withAmount;
}

float computeInt(float balance) {
    
    return balance * 0.03;
}

void displayClientRec(int accNum, char cName[], char cAdd[], float balance) {
    printf("Account Number: %d\n", accNum);
    printf("Name: %s\n", cName[]);
    printf("Address: %s\n", cAdd[]);
}