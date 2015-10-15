// COP 3514 - Program Design
// Matthew Coplan
// This program takes a dollar amount from a user input and calculates
// the amount of twenties, tens, fives, and ones needed
// dollar.c

#include <stdio.h>

// Define the dollar price of each dollar
#define TWENTY 20
#define TEN 10
#define FIVE 5

// function declaration
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int main()
{
	//initialize variables and read input
	int dollar = 0, twenty = 0, ten = 0, five = 0, one =0;
        printf("Enter a dollar amount:\n");
	scanf("%d", &dollar);

	//check the range of the input amount
	if (dollar < 0 || dollar > 1000000000)
		printf("Invalid amount %d,\nAmount must be between 0 and 1000000000, inclusive\n", dollar);
        else {
		pay_amount(dollar, &twenty, &ten, &five, &one);
		printf("$20 bills: %d\n", twenty);
	        printf("$10 bills: %d\n", ten);
        	printf("$5 bills: %d\n", five);
	        printf("$1 bills: %d\n", one);
	}

	return 0;
}

// function pay_amount calculates the amount of twenties, tens, fives, and ones needed
// and points back to the main function
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones)
{											
	*twenties = dollars / TWENTY;
	*tens = (dollars - (*twenties * TWENTY))/TEN;
	*fives = (dollars - (*twenties * TWENTY) - (*tens * TEN))/FIVE;
	*ones = (dollars - (*twenties * TWENTY) - (*tens * TEN) - (*fives * FIVE));
}
