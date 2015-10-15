// Program Design - COP 3514
// Matthew Coplan
// This program takes two strings and combines them letter by letter 
// forming an entirely new string of both the originals incremented
// merge.c

#include <stdio.h>
#include <string.h>

// each input no longer than 1000 characters
#define N 1000

// function declarations
int read_line(char *str, int n);
void merge(char *s3, const char *s1, const char *s2);

int main(void)
{
	char str[N+1], str2[N+1], str3[N+1];		// string 1, string 2, and string 3
	printf("This Program takes two strings and combines them letter by letter\n");
	printf("Enter the first string: \n");
	read_line(str, N);
	printf("Enter the second string: \n");
	read_line(str2, N);
	merge(str3, str, str2);
	printf("The string merged is: :  %s\n", str3);
	return 0;
}

// read_line function that performs getchar() until new line key is pressed
int read_line(char *str, int n)
{
	int ch, i = 0;
	
	while ((ch = getchar()) != '\n') {
		if (i < n) {
			*str++ = ch;
			i++;
		}
	}
	*str = '\0';
	return i;
}

// merge function that combines two strings letter by letter
void merge(char *s3, const char *s1, const char *s2)
{
	while(*s1 != '\0' && *s2 != '\0') {		// while loop to determine if both s1 and s2 are not at the end of the string
		strcpy(s3++, s1++);			// strcpy copies the element at s1[i] to s2[i] 
		strcpy(s3++, s2++);
	}

	*s3 = '\0';

	if (*s1 == '\0')				// if / else statement to catch any left over characters and appends to end of s3
		strcat(s3,s2);				// strcat appends s2 to s3
	else if (*s2 == '\0')
		strcat(s3,s1);				// strcat appends s1 to s3
}
