/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/

#include <stdio.h>
#include "factorial.h"

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
