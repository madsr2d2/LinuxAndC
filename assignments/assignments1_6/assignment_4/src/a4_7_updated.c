/*
Mandatory assignment: 4
Lesson: 7
Student name: Mads Richardt
Student Id: s224948
Date: 20/10/2022
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) { 

	srand(time(0));
	int guess;
	int counter;
	int select_var;
	int random_number;
	int oldInt = 0;
	int newInt = 1;
	int HIGH = 101;
	int LOW = 0;

	// Welcome message
	puts("**********");
	puts("Exercise 7");
	puts("**********\n");

	// Select exercise
	printf("1: SizeOfInt\n2: GuessANumber\n3: GuessANumberReverse\nPlease select option: ");
	scanf("%d", &select_var);

	// SizeOfInt
	if (select_var == 1) {
		puts("\n*********");
		puts("SizeOfInt");
		puts("*********");
		counter = -1;

		while (newInt != oldInt) {
			oldInt = newInt;
			newInt = 2*oldInt;
			counter ++;
		}

		printf("Number of bits in int: %d\n", counter);
	}

	// GuessAnumber
	if (select_var == 2) {
		puts("\n************");
		puts("GuessANumber");
		puts("************");
		random_number = rand()%100 + 1;
		counter = 0;

		while (guess != random_number) {
			counter++;
			printf("Guess number: ");
			scanf("%d", &guess);

			if (guess > random_number) {
				puts("Guess is larger than the secrete number");
			}
			else {
				puts("Guess is lower than the secrete number");
			}
		}
	
		printf("Correct!!!\nYou guessed the secrete number on guess %d\n", counter);
	}

	// GuessANumberReverse
	if (select_var == 3) {
		puts("\n*******************");
		puts("GuessANumberReverse");
		puts("*******************\n");
		counter = 0;
		printf("Enter number in the range [%d - %d]: ", LOW, HIGH-1); // Get number from user
		scanf("%d", &random_number);

		while (random_number != guess) {
			guess = LOW + (HIGH - LOW)/2;
			counter++;
			printf("Guess %d: %d\n",counter, guess);

			if (guess > random_number) {
				HIGH = guess;
			}
			else {
				LOW = guess;	
			}
		}
	}
	
	return 0; // Program  terminated without error
}