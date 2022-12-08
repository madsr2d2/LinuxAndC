/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/
#include <stdio.h>
#include "factorial.h"
void ex11_2()
{
    int selectVar = 0;
    unsigned long input;
    unsigned long fac;
    while (selectVar != 2) {
        printf("1: Compute factorial\n2: Exit exercise 11.2\nPlease choose option: ");
        scanf("%1d", &selectVar);
        while(getchar() != '\n') {};
        
        if (selectVar == 1) {
            printf("\nEnter positive integer: ");
            scanf("%lu", &input);
            fac = factorial(input);
            
            if (fac == 0) {
                puts("Overflow! Number is to large.\n");
            }
            else {
                printf("%lu! = %lu\n", input, fac);
            }
        }
    }
}