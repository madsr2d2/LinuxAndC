/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/

#include <stdio.h>
#include "ex11_1.h"
#include "ex11_2.h"

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