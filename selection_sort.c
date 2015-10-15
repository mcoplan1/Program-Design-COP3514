// Program Design - COP3514
// Matthew Coplan
// This program sorts an array from smallest to lowest
// selection_sort.c

#include <stdio.h>
#define N 10

// function declarations
void selection_sort(int *a, int n);
int *find_largest(int *a, int n);
void swap(int *p, int *q);

int main(void)
{
	int i;
	int a[N];

	printf("Enter %d numbers to be sorted: \n", N); // grab array from user and sort
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	selection_sort(a, N);				// function call and sort new array

	printf("In sorted order: ");
	for (i = 0; i < N; i++) {
		printf(" %d", a[i]);
  	}
	printf("\n");

  	return 0;
}

// selection_sort recursively calls the function until n equals 1
void selection_sort(int *a, int n)
{
	int *p = a;
	int *i;
	int *j;

	if (n == 1) {
		return;
   	}

	i = (p+n-1);					// assign i to a[N], the last array element
	j = find_largest(a, n);				// assign j to the largest value

	swap(i, j);					// swap i and j
	
	selection_sort(a, n - 1);			// recursive call
	
}

// find_largest finds the largest value in the array and returns
int *find_largest(int *a, int n)
{
	int *p;
	int *p_max = a;					// set p_max to a[0]
	
	for(p = a + n -1; p >= a; p--) {		// start loop at end of array and decrease
		if ( *p > *p_max)		
			p_max = p;
	}
	return p_max;
}

// swap switches the largest value to the end of an array
void swap(int *p, int *q)
{
	int temp = *p;
	*p = *q;
	*q = temp;
}
