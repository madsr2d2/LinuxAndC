#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {

	srand(time(0));
	int guess;
	int guess_counter = 0;
	int select_var;
	int random_number;

	// Welcome message
	puts("**********");
	puts("Exercise 7");
	puts("**********");
	puts("");

	printf("1: GuessANumber\n2: GuessANumberReverse\nPlease select option: ");
	scanf("%d", &select_var);

	// GuessAnumber
	if (select_var == 1) {

		
		random_number = rand()%100 + 1;
		puts("");
		puts("************");
		puts("GuessANumber");
		puts("************");
	
		while(1) {
			guess_counter++;
			printf("Guess number: ");
			scanf("%d", &guess);

			if (guess == random_number) {
				puts("Correct!!!");
				printf("You guessed the secrete number on guess %d\n", guess_counter);
				break;
			}

			if (guess > random_number) {
				puts("Guess is larger than the secrete number");
			}
			else {
				puts("Guess is lower than the secrete number");
			}
		}
	}

	// GuessANumberReverse
	if (select_var == 2) {
		int HIGH = 100;
		int LOW = 0;
		puts("");
		puts("*******************");
		puts("GuessANumberReverse");
		puts("*******************");
		puts("");

		// Get number fro user
		printf("Enter number: ");
		scanf("%d", &random_number);


		while(guess_counter < 20) {
			guess = LOW + (HIGH - LOW)/2;
			guess_counter++;
			printf("Guess: %d\n", guess);
			//printf("Low: %d\n",LOW);
			//printf("High: %d\n",HIGH);
			//puts("");
			if (random_number == guess) {
 				printf("I guessed your number on guess %d", guess_counter);
				break;
			}
			if (guess > random_number) {
				HIGH = guess;
			}
			else {
				LOW = guess;	
			}
		}
	}
	
	// Program  terminated without error
	return 0;
}
