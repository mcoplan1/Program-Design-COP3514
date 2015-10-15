// Program Design - COP 3514
// Matthew Coplan
// This program sorts 10 numbers through command line function calls
// by either ascending sort or descending sort
// command_sort.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// function declarations
void ascending_sort(int a[], int n);
void descending_sort(int a[], int n);

int main(int argc, char *argv[])
{
	int i;
	char find_d[3] = "-d";			// find "-d" in function
	char find_a[3] = "-a";			// find "-a" in function
	int command_d;				// command d
	int command_a;				// command a
	char *find_command_d = argv[1];
	char *find_command_a = argv[1];		// find specific command in program
	int toInt[12];				// convert string to Int for sort

	for( i = 0; i < argc; i++){		// display input
		printf("%s ", argv[i]);
	}
	printf("\n");

	command_d = strcmp(find_command_d, find_d);	// find "-d" in input
	command_a = strcmp(find_command_a, find_a);	// find "-a" in input

 	if (command_d == 0) {				// If/else to sort command_d == 0, then command_d = "-d"
		printf("In descending order: ");
		for(i = 0; i<argc; i++) {
			toInt[i] = atoi(argv[i]);	// change string to int form
		}
		descending_sort(toInt, argc);		// call function
		for(i = 2; i <argc; i++) {		// display the descending sort
			printf(" %d", toInt[i]); 
		}
	}
	else if (command_a == 0) {			// else to sort command_a == 0, then command_a = "-a"
		printf("In ascending order: ");
		for(i = 0; i < argc; i++) {
			toInt[i] = atoi(argv[i]);	// change string to int form
}
		ascending_sort(toInt, argc);		// call function
		for(i = 2; i < argc; i++) {		// display ascending sort
			printf(" %d", toInt[i]);
		}
	}
		else {
			printf("Invalid command: %s\n", find_command_a); 	// to catch erroneous commands
		}
	printf("\n");
	return 0;
}

// ascending_sort function
void ascending_sort(int a[], int n) 
{   
	int i, largest = 0, temp;
 
 	if (n == 1)    
		 return;

  	for (i = 1; i < n; i++)     
		if (a[i] > a[largest])       
			largest = i;
			
	if (largest < n - 1) {     
		temp = a[n-1];     
		a[n-1] = a[largest];     
		a[largest] = temp;   
	}
 	 ascending_sort(a, n - 1); 
}

// descending_sort function
void descending_sort(int a[], int n)
{
	int i, largest = 2, temp;

	if(n == 1)
		return;

	for (i = n-1; i > 2; i--) 	// start loop index from end of array and sort through
		if(a[i] < a[largest])
			largest = i;
	if (largest < n - 1) {
		temp = a[n-1];
		a[n-1] = a[largest];
		a[largest] = temp;
	}
	descending_sort(a, n-1);
}
