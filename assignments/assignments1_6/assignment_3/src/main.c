/*
Pseudo code:
	Print welcome message.
	Repeat until user wants to close program: 
		Get text to search from user.
		Get set to search for from user.
		Count number of times members of set appear in text.
		Print result of count.
*/

#include <stdio.h>
#include "countCharactersInSet.h"
#define MAX_LENGTH 100

int main()
{
	char  myText[MAX_LENGTH + 1]; // array to contain text
	char  mySet[MAX_LENGTH + 1]; // array to contain search set
	int result;
	int control_var = 1;

	puts("***********************");
	puts("Welcome to Assignment 6");
	puts("***********************");


	do {
		// Get text to search.
		printf("\nEnter text (Max length %d): ",MAX_LENGTH);
		fgets(myText,MAX_LENGTH+1,stdin);

		// Get set to search for.
		printf("\nEnter search set (Max length %d): ",MAX_LENGTH);
		fgets(mySet,MAX_LENGTH+1, stdin);

		// Get results.
		result = countCharactersInSet(myText, mySet);

		// Print results
		printf("\nNumber of hits: %d\n", result);

		// Check if user wants to try again.
		printf("\n1: Try again.\n2: Exit program.\nPlease choose option: ");
		scanf("%d",&control_var);

		// Clear stdin
		while (getchar() != '\n') {}
	} while (control_var != 2);

	// Close Program.
	puts("\nClosing program...");
	return 0; 
}