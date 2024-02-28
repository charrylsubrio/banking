#include <stdio.h>
#include <string.h>

float balance;

int acceptAccNum(void);
float acceptAmount(void);
float computeDepBalance(float, float);
float computeWithBalance(float, float);
float computeInt(float);
void displayClientRec(int, char, char, float);
float acceptInitialBalance(void);

int main() {
	int accNum;
	
	
}

int acceptAccNum(void) {
	int accNum;
	
	printf("Input Account Number: ");
	scanf("%d", &accNum);
}