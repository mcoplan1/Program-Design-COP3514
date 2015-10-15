// COP 3514 Program Design
// Matthew Coplan
//
// This program takes two fractions seperated by an operator and adds, subtracts, multiplys, or divides
// depending on what the user enters
// fraction.c

#include <stdio.h>

int main(void)
{	
	int fractionNum1, fractionDem1 = 0;		// Fraction One
	int fractionNum2, fractionDem2 = 0;		// Fraction Two
	int newDem, newNum = 0;				// New fraction after calculations
	char operator;					// operator grabbed from user input

	printf("Enter two fractions separated by an operator(+ , - , / , * ):\n");
	scanf("%d/%d  %c %d/%d", &fractionNum1, &fractionDem1, &operator, &fractionNum2, &fractionDem2); 	// Skip space before and after %c to catch white space

	switch (operator) {											// Switch statement to process input calculations
		case '+': 											// Add
			   if ( fractionDem1 == fractionDem2 ) 							// If/else statement to determine if demoninator is the same 
			   {	newNum = fractionNum1 + fractionNum2;						// or different
				newDem = fractionDem1;								// Calculations
				printf("The sum is %d/%d\n", newNum, newDem);
			   }
		  	   else { 
				newDem = fractionDem1 * fractionDem2;
				fractionNum1  = fractionNum1 * fractionDem2;
				fractionNum2  = fractionNum2 * fractionDem1;
			 	newNum = fractionNum1 + fractionNum2;
				printf("The sum is %d/%d\n", newNum, newDem);
			   }
		           break;
		case '-':											// Subtract
			   if ( fractionDem1 == fractionDem2 ) 							// If/else statement to determine if demoninator is the same
			   { 	newNum = fractionNum1 - fractionNum2;						// or different
				newDem = fractionDem1;								// Calculations
				printf("The difference is %d/%d\n", newNum, newDem);
			   }
			   else { 
				newDem = fractionDem1 * fractionDem2;
				fractionNum1 = fractionNum1 * fractionDem2;
				fractionNum2 = fractionNum2 * fractionDem1;
				newNum = fractionNum1 - fractionNum2;
				printf("The difference fraction is %d/%d\n", newNum, newDem);
			   }
		           break;
		case '*':											// Multiply
			   newNum = fractionNum1 * fractionNum2;						// Calculations
			   newDem = fractionDem1 * fractionDem2;
			   printf("The product is %d/%d\n", newNum, newDem);
			   break;
		case '/':											// Divide
			   newNum = fractionNum1 * fractionDem2;						// Calculations
			   newDem = fractionDem1 * fractionNum2;
			   printf("The quotient is %d/%d\n", newNum, newDem);
			   break;
		default: 											// Default statement to catch erroneous values for operators
			   printf("You entered an invalid operator: %c , Program aborted.\n", operator);
			   break;	
	}
	return 0;
}
