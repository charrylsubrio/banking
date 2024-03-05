#include <stdio.h>
#include <string.h>

//global variable
int gradYr;

//function prototypes
int getYearLvl(void);
int computeGradYr(int);
void displayResults(char[], int, int);

int main() {
	//local variables
	char name[50];
	int yearLvl;
	
	printf("==== GRAD YEAR CALCULATOR FOR BSIT STUDENTS ====\n\n");
	printf("Enter Your Name: ");
	gets(name);
	system("cls");
	
	yearLvl = getYearLvl();
	gradYr = computeGradYr(yearLvl);
	displayResults(name, yearLvl, gradYr);	
		
	return 0;
}

//function definitions
int getYearLvl(void) {
	int yearLvl;
	
	do{
		printf("==== GRAD YEAR CALCULATOR FOR BSIT STUDENTS ====\n\n");
		printf("[1] - First Year\n");
		printf("[2] - Second Year\n");
		printf("[3] - Third Year\n");
		printf("[4] - Fourth Year\n\n");
		
		printf("Enter Your Year level: ");
		scanf("%d", &yearLvl);
		
		if(yearLvl < 1 || yearLvl > 4) {
			printf("\nInvalid. Please input 1 - 4 only.");
			printf("\nPress any key to continue ... ");
			getch();
			system("cls");
		}
	} while(yearLvl < 1 || yearLvl > 4);
	
	
	system("cls");
	
	return yearLvl;		
}

//function with 1 formal paramter
int computeGradYr(int yearLvl) {
	gradYr = 2024 + (4 - yearLvl);
	
	return gradYr;
}

//function with multiple formal parameters
void displayResults(char name[], int yearLvl, int gradYr){
	printf("==== GRAD YEAR CALCULATOR FOR BSIT STUDENTS ====\n\n");
	printf("Hi %s! You're on track to graduate in %d. \n\nKeep up the coding, and remember, the future is digital!\n", name, gradYr);
}