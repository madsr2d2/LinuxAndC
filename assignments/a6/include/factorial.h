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