// Program Design - COP3514
// Matthew Coplan
// This program creates two arrays from user input and determines the dot product
// aswell as checks to see if the arrays are the same
// vector.c

#include <stdio.h>

//function declarations
void multi_vec(int *v1, int *v2, int *v3, int n);
int comp_vec(int *v1, int *v2, int n);

int main(void)
{
	int n, i;
	int countVector;					// function comp_vec passes the count to this 
	printf("Enter the length of the two vectors\n");
	scanf("%d", &n);
	int v1[n], v2[n], v3[n];				// initalize array elements after index is grabbed from user
	
	printf("Enter %d numbers for the first array\n", n);	// fill arrays
	for (i = 0; i < n; i++) {
		scanf("%d", &v1[i]);
	}
	printf("Enter %d numbers for the second array\n", n);
	for (i = 0; i < n; i++) {
		scanf("%d", &v2[i]);
	}
	
	multi_vec(v1, v2, v3, n);				// perform dot product on array elements
	printf("The multiplication of the vectors is: ");
	for (i = 0; i < n; i++) {				// fill new array
		printf("%d ", v3[i]);
	}
	printf("\n");

	countVector = comp_vec(v1, v2, n);			// compare the count from comp_vec to the index n
	if ( countVector == n ) 				// if they are the same then both the arrays are the same
		printf("The vectors are the same \n");		// else they are different
	else
		printf("The vectors are different \n");
	return 0;

}

// function multi_vec performs dot product of the two arrays
void multi_vec(int *v1, int *v2, int *v3, int n)
{
	int i;
	for (i = 0; i < n; i++) {
		*(v3+i) = *(v1+i) * *(v2+i);			// v3[i] = v1[i] * v2[i]
	}
}

// function comp_vec determines if the two arrays are similar
// if they are similar at v1[i] and v2[i]. count++
// if count++ == n, then the arrays are the same
int comp_vec(int *v1, int *v2, int n)
{
	int i;
	int count = 0;
	
	for(i = 0; i < n; i++) {
		if( *(v1+i) == *(v2+i)) 
			count++;
	}
	return count;
}
