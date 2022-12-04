/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/

#include <stdio.h>
#include "factorial.h"
#include "weekTemp.h"

void ex11_1();
void ex11_2();

int main(void) {
	int selectVar = 0;
	puts("***********************");
	puts("Welcome to Assignment 6");
	puts("***********************");

	while (selectVar != 3) {
		puts("\n**********");
		puts("Main menu");
		puts("**********");
		printf("1: Exercise 11.1\n2: Exercise 11.2\n3: Close program\nPlease choose option: ");
		scanf("%1d", &selectVar);
		getchar();

		switch (selectVar) {
			case 1:
				puts("\n*************");
				puts("Exercise 11.1");
				puts("*************");
				ex11_1();
				break;
			case 2:
				puts("\n*************");
				puts("Exercise 11.2");
				puts("*************");
				ex11_2();
				break;
			default:
				break;
		}
	}

	puts("\nClosing program...");
	return 0;
}

void ex11_1() {
	int selectVar = 0; 
	WeekTemp week;
	int demoWeek[] = {18, 16, 14, 13, 14, 17, 17};
	int newWeek[7];

	while (selectVar != 6) {
		printf("1: Load demo week.\n2: Load new week.\n3: Compute mean temperature.\n4: Compute median temperature.\n5: Compute standard deviation.\n6: Exit exercise 11.1.\nPlease choose option: ");
		scanf("%1d", &selectVar);
		getchar();

		switch (selectVar) {
			case 1:
				puts("");
				week.loadWeek(demoWeek);
				break;
			case 2:
				puts("");

				for (int i = 0; i < 7; i++) {
					printf("Enter temperature for day %d: ", i + 1);
					scanf("%d",&newWeek[i]);
					getchar();		
				}

				week.loadWeek(newWeek);
				puts("");
				break;
			case 3:
				printf("\nMean temperature: %.1f", week.meanTemp());
				puts("\n");
				break;
			case 4:
				printf("\nMedian temperature: %d", week.medianTemp());
				puts("\n");
				break;
			case 5:
				printf("\nStandard deviation: %.1f", week.SD());
				puts("\n");
				break;
			default:
				break;
		}
	}
}

void ex11_2() {
	int selectVar = 0;
	unsigned long input;

	while (selectVar != 2) {
		printf("1: Compute factorial\n2: Exit exercise 11.2\nPlease choose option: ");
		scanf("%d", &selectVar);
		getchar();
		
		if (selectVar == 1) {
			printf("\nEnter positive integer: ");
			scanf("%lu", &input);
			getchar();
			printf("%lu! = %lu", input, factorial(input));
			puts("\n");
		}
	}
}
