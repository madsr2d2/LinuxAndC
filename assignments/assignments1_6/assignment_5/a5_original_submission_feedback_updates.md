---
title:  Assignment 5
subtitle: Linux and C Programming (62558)
author: Mads Richardt (s224948)
date: \today
documentclass: article
geometry: margin=30mm
colorlinks: true 
boxlinks: true
...

# Feedback
9.2
Fine solution.

9.3
Fine solution, but be aware that nested function only works with gcc.

10.1
Good answer.

# Original Submission

## Exercise 9.1
Count number of times n gets assigned the number six.

## Answer
Each time through the loop n gets assigned a value from 1-6, at random. Accordingly, the number six's assigned to n varies each time the program is run. I ran the program 3 times and got 3, 2 and 2 six's, respectively.

## Source Code
```cpp
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
unsigned long Factorial(int n);

int main() 
{
	puts("***********************");
	puts("Welcome to Assignment 5");
	puts("***********************");

	int selectionVariable = 0;

	while (selectionVariable != 4)
	{
		// Prompt user for selection.
		printf("\n1: Diceman.\n2: Stack Trace.\n3: Factorial.\n4: Close Program.\nPlease choose option: ");
		scanf("%1d",&selectionVariable);

		switch (selectionVariable)
		{
			case 1:
				puts("");
				puts("*******");
				puts("Diceman");
				puts("*******");

				printf("Rolling dice... ");
				// Call Diceman().
				Diceman();
				break;

			case 2:
				puts("");
				puts("***********");
				puts("Stack Trace");
				puts("***********");

				// Call f1().
				f1();
				break;

			case 3:
				puts("");
				puts("***********");
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
}

// Function definition.
void Diceman()
{
	char action [100];

	// Role dice
	srand(time(0));
	int dice = rand() % 6 + 1;
	
	switch (dice)
	{
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

void f1() 
{
	void f2() 
	{
		void f3()
		{
			void f4()
			{
				void f5()
				{
					puts("f5() called");
				}
				puts("f4() called");
				f5();
			}
			puts("f3() called");
			f4();
		}
		puts("f2() called");
		f3();
	}
	puts("f1() called");
	f2();
}

unsigned long Factorial(int n)
{
	unsigned long f = 1;
	for (int i = 1; i <= n; i++)
	{
		f = f*i;
	}
	return f;
}
```

# Updates
In the updated submission listed below, I "denested" the the function f1() from exercise 9.3.
``` cpp
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
```



