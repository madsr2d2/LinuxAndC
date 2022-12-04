/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/

#ifndef FACTORIAL
#define FACTORIAL

// Factorial function.
unsigned long factorial(unsigned long n)
{
    unsigned long f = 1;
    for (unsigned long i = 1; i <= n; i++)
    {
        f = f * i;
    }
    return f;
}

#endif