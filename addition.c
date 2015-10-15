//
// COP 3514 - Program Design 
// Matthew Coplan
// This program takes two numbers and add's them recursively
// addition.c
// 

#include <stdio.h>

int add_numbers(int numberOne, int numberTwo);				// function

int main (void)
{	
	int numberOne = 0;						// first number from user
	int numberTwo = 0;						// second number from user
	int finalNumber;						// the sum of numberOne and numberTwo
	
	printf("This program takes two numbers and adds them\n");	//Program information and user input
	printf("Enter the first number:\n");
	scanf("%d", &numberOne);
	printf("Enter the second number:\n");
	scanf("%d", &numberTwo);

	finalNumber = add_numbers(numberOne, numberTwo);		// Display finalNumber
	printf("The sum is: %d\n", finalNumber);
	return 0;

}

int add_numbers(int numberOne, int numberTwo)
{
	if (numberOne == 0)						// If Statement to catch when numberOne and numberTwo are equal to zero
		return numberTwo;
	else if (numberTwo == 0 )
		return numberOne;		
	else if (numberOne < 0)						// If statement to catch when numberOne and NumberTwo are less than zero
		return add_numbers(++numberOne, --numberTwo);
	else if (numberTwo < 0 )
		return add_numbers(--numberOne, ++numberTwo);
	else if (numberOne >= numberTwo)				// If statement to catch when numberOne is larger than numberTwo
		return add_numbers(++numberOne, --numberTwo);
	else 								// else statement to catch when numberTwo is larger than numberOne
		return add_numbers(--numberOne, ++numberTwo);
}
