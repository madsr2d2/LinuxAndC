---
title:  Assignment 6
subtitle: Linux and C Programming (62558)
author: Mads Richardt (s224948)
date: \today
documentclass: article
geometry: margin=30mm
colorlinks: true 
boxlinks: true
...

# Feedback
Your header files should not include source code, but only function prototypes, data types and macros.
And I couldn't get 11.2 to compile with either g++ or gcc. The code looks fine, but it is expected that it is solved using plain c and not cpp.



# Original Submission
```cpp
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

int main(void)
{
	int selectVar = 0;

	puts("***********************");
	puts("Welcome to Assignment 6");
	puts("***********************");

	while (selectVar != 3)
	{
		puts("");
		puts("**********");
		puts("Main menue");
		puts("**********");
		printf("1: Exercise 11.1\n2: Exercise 11.2\n3: Close program\nPlease choose option: ");
		scanf("%1d", &selectVar);
		getchar();

		switch (selectVar)
		{
			case 1:
				puts("");
				puts("*************");
				puts("Exercise 11.1");
				puts("*************");
				ex11_1();
				break;
			case 2:
				puts("");
				puts("*************");
				puts("Exercise 11.2");
				puts("*************");
				ex11_2();
				break;
			default:
				break;
		}
	}
	puts("");
	puts("Closing program...");
}

void ex11_1()
{
	int selectVar = 0; 
	WeekTemp week;
	int demoWeek[] = {18, 16, 14, 13, 14, 17, 17};
	int newWeek[7];

	while (selectVar != 6)
	{
		printf("1: Load demo week.\n2: Load new week.\n3: Compute mean temperature.\n4: Compute median temperature.\n5: Compute standard deviation.\n6: Exit exercise 11.1.\nPlease choose option: ");
		scanf("%1d", &selectVar);
		getchar();

		switch (selectVar)
		{
			case 1:
			{
				puts("");
				week.loadWeek(demoWeek);
				break;
			}
			case 2:
			{
				puts("");
				for (int i = 0; i < 7; i++)
				{
					printf("Enter temperature for day %d: ", i + 1);
					scanf("%d",&newWeek[i]);
					getchar();		
				}
				week.loadWeek(newWeek);
				puts("");

				break;
			}
			case 3:
			{
				puts("");
				printf("Mean temperature: %.1f", week.meanTemp());
				puts("");
				puts("");

				break;
			}
			case 4:
			{
				puts("");
				printf("Median temperature: %d", week.medianTemp());
				puts("");
				puts("");

				break;
			}
			case 5:
			{
				puts("");
				printf("Standard deviation: %.1f", week.SD());
				puts("");
				puts("");

				break;
			}
			default:
				break;
		}
	}
}

void ex11_2()
{
	int selectVar = 0;
	unsigned long input;
	while (selectVar != 2)
	{
		printf("1: Compute factorial\n2: Exit exercise 11.2\nPlease choose option: ");
		scanf("%d", &selectVar);
		getchar();
		
		if (selectVar == 1)
		{
			puts("");
			printf("Enter positive integer: ");
			scanf("%lu", &input);
			getchar();

			printf("%lu! = %lu", input, factorial(input));
			puts("");
			puts("");
		}
	}
}
```

# Updates
In the updated submission listed below, I have separated out the function definitions from the header files. Function definitions are now located in the files factorial.cpp, weekTemp.cpp, ex11_1.cpp and ex11_2.cpp.

## Header Files

### factorial.h
```cpp
/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/

#ifndef FACTORIAL
#define FACTORIAL

// Computes the factorial.
unsigned long factorial(unsigned long n);

#endif
```

### weekTemp.h
```cpp
/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/

#ifndef WEEKTEMP
#define WEEKTEMP

// A class for storing temperatures for a week.
class WeekTemp {
    private:
        // Array of week temperatures.
        int weekTemps[7];
        // Array of sorted week temperatures.
        int sortedWeekTemps[7];         
    public:
        // Constructor.
        WeekTemp();                     
        // Load week function
        int loadWeek(int *weekTempArr);
        // Function to compute mean temperature.
        float meanTemp();
        // Function to compute median temperature.
        int medianTemp();
        // Function to compute the standard deviation.
        float SD();
        // Returns a pointer to a copy of WeekTemps in heap.
        int *getWeek();                 
};

#endif
```

### ex11_1.h
```cpp
/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/

#ifndef EX11_1
#define EX11_1

// Function for running exercise 11.1
void ex11_1();

#endif 
```

### ex11_2.h
```cpp
/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/

#ifndef EX11_2
#define EX11_2

// Function for running exercise 11.2
void ex11_2();

#endif 
```
## Source Files

### main.cpp
```cpp
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
```
### factorial.cpp
```cpp
/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/

#include "factorial.h"

unsigned long factorial(unsigned long n) {
    unsigned long f = 1;
    for (unsigned long i = 1; i <= n; i++) {
        f = f * i;
    }
    return f;
}
```
### weekTemp.cpp
```cpp
/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/

#include <algorithm>
#include <cmath>
#include "weekTemp.h"

WeekTemp::WeekTemp(){}

int WeekTemp::loadWeek(int *weekTempArr) { 
    int i;
    for (i = 0; i < 7; i++) {
        weekTemps[i] = weekTempArr[i];
    }
    std::copy(weekTemps, weekTemps + 7, sortedWeekTemps);
    std::sort(sortedWeekTemps, sortedWeekTemps + 7);
    return i;
}

float WeekTemp::meanTemp() {
    int sum = 0;
    
    for (int i = 0; i < 7; i++) {
        sum += weekTemps[i];
    }
    return sum / 7.0;
}

int WeekTemp::medianTemp() {
    return sortedWeekTemps[3];
}

float WeekTemp::SD() {
    float variance = 0;
    float mean = meanTemp();
    for (int i = 0; i < 7; i++) {
        variance += (weekTemps[i] - mean) * (weekTemps[i] - mean);
    }
    return sqrt(variance / 7);
}

int *WeekTemp::getWeek() {
    int *weekTempsCopy = new int[7];
    std::copy(weekTemps, weekTemps + 7, weekTempsCopy);
    return weekTempsCopy;
}
```

### ex11_1.cpp
```cpp
/*
Course name: Linux and C Programming (62558)
Student name: Mads Richardt
Student Id: s224849
Date: 17-11-2022
*/

#include "weekTemp.h"
#include "ex11_1.h"
#include <stdio.h>

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
                    scanf("%d", &newWeek[i]);
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
```

### ex11_2.cpp
```cpp
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

```
