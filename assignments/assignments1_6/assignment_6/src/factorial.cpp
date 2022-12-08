/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/
#include "factorial.h"

// Return 0 if overflow. 
unsigned long factorial(unsigned long n) {
    unsigned long f = 1;
    for (unsigned long i = 1; i <= n; i++) {

        // Return 0 if overflow.
        if (f == f * i && i > 1)
        {
            return 0;
        }
        f = f * i;
    }
    return f;
}