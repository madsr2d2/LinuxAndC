/*
Mandatory assignment: 5
Lesson: 9 + 10
Student Name: Mads Richardt
Student Id: s224948
Date: 04/11/2022
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function declarations
void Diceman();
void f1();
void f2();
void f3();
void f4();
void f5();
unsigned long Factorial(int n);

int main() {
	puts("***********************");
	puts("Welcome to Assignment 5");
	puts("***********************");

	int selectionVariable = 0;

	while (selectionVariable != 4) {
		// Prompt user for selection.
		printf("\n1: Diceman.\n2: Stack Trace.\n3: Factorial.\n4: Close Program.\nPlease choose option: ");
		scanf("%1d",&selectionVariable);

		switch (selectionVariable) {
			case 1:
				puts("\n*******");
				puts("Diceman");
				puts("*******");

				printf("Rolling dice... ");
				// Call Diceman().
				Diceman();
				break;

			case 2:
				puts("\n***********");
				puts("Stack Trace");
				puts("***********");

				// Call f1().
				f1();
				break;

			case 3:
				puts("\n***********");
				puts("Factorial");
				puts("***********");

				// Prompt user for integer. 
				int k;
				printf("Enter a positive integer: ");
				scanf("%d", &k);

				// Call Factorial().
				unsigned long fk = Factorial(k);

				// Print result.
				printf("The value of %u factorial is %lu\n",k, fk);
				break;

			default:
				break;
		}
	}
	puts("\nClosing Program...");
	return 0;
}

// Function definition.
void Diceman() {
	char action [100];

	// Role dice
	srand(time(0));
	int dice = rand() % 6 + 1;
	
	switch (dice) {
	case 1:
		strcpy(action,"Breakfast!");
		printf("%d! %s\n",dice, action);
		break;
	case 2:
		strcpy(action, "Study!");
		printf("%d! %s\n",dice, action);
		break;
	case 3:
		strcpy(action, "Swim!");
		printf("%d! %s\n",dice, action);
		break;
	case 4:
		strcpy(action, "Go fishing!");
		printf("%d! %s\n",dice, action);
		break;
	case 5:
		strcpy(action, "Call mom!");
		printf("%d! %s\n",dice, action);
		break;
	case 6:
		strcpy(action, "Back to bed!");
		printf("%d! %s\n",dice, action);
		break;
	default:
		break;
	}
}

void f5() {}

void f4() {
	f5();
}

void f3() {
	f4();
}

void f2() {
	f3();
}

void f1() {
	f2();
}

unsigned long Factorial(int n)
{
	unsigned long f = 1;
	for (int i = 1; i <= n; i++) {
		f = f*i;
	}
	return f;
}