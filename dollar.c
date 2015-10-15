//
// Program Design - 2015
// Matthew Coplan
// This program asks the user to enter a dollar amount then converts into appropriate
// 20, 10, 5, and 1 dollar bills as necessary
//

#include <stdio.h>

#define TWENTY 20
#define TEN 10
#define FIVE 5
#define ONE 1 

int main(void)
{
	int amountEntered = 0; //The amount of dollars the user enters
	int twentyBills;       //The amount of twenty dollar bills
	int tenBills;          //The amount of ten dollar bills
	int fiveBills;         //The amount of five dollar bills
	int oneBills;	       //The amount of one dollar bills
	
	
	printf("This program will take the dollar amount entered and convert it into appropriate bills as necessary\n"); // Grab information from user
	printf("Please enter a dollar amount between 0 and 1000000000\n");
	scanf("%d" , &amountEntered); 
	
	if ((amountEntered >= 0) && (amountEntered <= 1000000000)) {  // If/else statement to catch wrong values
		twentyBills = amountEntered / TWENTY;
		amountEntered = amountEntered - twentyBills*TWENTY;
		
		tenBills = amountEntered / TEN;
		amountEntered = amountEntered - tenBills*TEN;

		fiveBills = amountEntered / FIVE;
		amountEntered = amountEntered - fiveBills*FIVE;

		oneBills = amountEntered / ONE;
		amountEntered = amountEntered - oneBills*ONE;	
	
		printf("The number of each type of dollar bill is as follows:\n"); // Print each dollar amount
		printf("The number of Twenty dollar bills: %d\n" , twentyBills);
		printf("The number of Ten dollar bills: %d\n" , tenBills);
		printf("The number of Five dollar bills: %d\n" , fiveBills);
		printf("The number of One dollar bills: %d\n" , oneBills);
	}
	else {
		printf("Invalid Amount: %d\n", amountEntered); 	// Error Message
		printf("Amount must be between 0 and 1000000000\n"); 
	}
	return(0); 
}
