// Program Design - COP3514
// Matthew Coplan
// This program takes two fractions separated by an operator and reduces them
// by finding the gcd and divinding the num and den by that gcd
// fraction_math.c

#include <stdio.h>

// Function declarations
void reduce(int numerator, int denominator, int* reduced_numerator, int* reduced_denominator);
int find_gcd(int m, int n);

int main(void)
{
	int num1, denom1, num2, denom2, result_num, result_denom;	// variable declarations
	char operator;							
	int num, dem;							// final numerator, and denominator

	printf("Enter two fractions separated by a +, -, * or / sign: ");	// Grab information from user
	scanf("%d/%d %c%d/%d", &num1, &denom1, &operator, &num2, &denom2);

	switch (operator) {							// switch statement to catch operator
		case '+':							// each case calls the reduce function in order
			result_num = num1 * denom2 + num2 * denom1;		// to properly reduce each fraction
			result_denom = denom1 * denom2;
			reduce(result_num, result_denom, &num, &dem);
			printf("The sum is %d/%d\n", num, dem);
			break;
		case '-':
			result_num = num1 * denom2 - num2 * denom1;
			result_denom = denom1 * denom2;
			reduce(result_num, result_denom, &num, &dem);
			printf("The difference is %d/%d\n", num, dem);
			break;
		case '*':
			result_num = num1 * num2;
			result_denom = denom1 * denom2;
			reduce(result_num, result_denom, &num, &dem);
			printf("The product is %d/%d\n", num, dem);
			break;
		case '/':
			result_num = num1 * denom2;
			result_denom = denom1 * num2;
			reduce(result_num, result_denom, &num, &dem);
			printf("The quotient is %d/%d\n", num, dem);
			break;
		default:							// default case to catch an operator that isnt, +, -, *, /
			printf("Unrecognized operator: %c\n", operator);
	}
	return 0;
}


void reduce(int numerator, int denominator, int* reduced_numerator, int* reduced_denominator)	//reduce function
{												
	*reduced_numerator = numerator / find_gcd(numerator, denominator);			//takes result_num and divides by gcd
	*reduced_denominator = denominator / find_gcd(numerator, denominator);			//takes result_denom and divides by gcd
}
int find_gcd(int m, int n)						// gcd function
{
	if(n == 0) { 
		return m;
	}
	return find_gcd(n, m%n);
}
