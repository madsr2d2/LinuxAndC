#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function declarations
void Diceman();
void StackTrace();

int main() {
	puts("***********************");
	puts("Welcome to Assignment 5");
	puts("***********************");

	int selectionVariable = 0;

	while (selectionVariable != 4) {
	
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
			Diceman();
			break;

		case 2:
			puts("");
			puts("*******");
			puts("Stack Trace");
			puts("*******");
			StackTrace();

		default:
			break;
		}

	}

	puts("\nClosing Program...");
}

void Diceman() {
	char action [100];

	// Role dice
	srand(time(0));
	int dice = rand() % 6 + 1;
	
	switch (dice)
	{
	case 1:
		strcpy(action,"Breakfast!");
		printf("%s\n", action);
		break;
	case 2:
		strcpy(action, "Study!");
		printf("%s\n", action);
		break;
	case 3:
		strcpy(action, "Swim!");
		printf("%s\n", action);
		break;
	case 4:
		strcpy(action, "Go fishing!");
		printf("%s\n", action);
		break;
	case 5:
		strcpy(action, "Call mom!");
		printf("%s\n", action);
		break;
	case 6:
		strcpy(action, "Back to bed!");
		printf("%s\n", action);
		break;
	default:
		break;
	}
}

void StackTrace() {
	
}