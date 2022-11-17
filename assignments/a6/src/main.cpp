#include <stdio.h>
#include "factorial.h"
#include "weekTemp.h"
int main(void)
{
	//unsigned long res = factorial(10);
	//printf("%lu", res);
	int selectVar = 0;
	int newWeek[7];

	puts("***********************");
	puts("Welcome to Assignment 6");
	puts("***********************");
	puts("");
	WeekTemp week;

	while (selectVar != 6)
	{
		printf("1: Load demo week.\n2: Load new week.\n3: Compute mean temperature.\n4: Compute median temperature.\n5: Compute standard deviation.\n6: Close Program.\nPlease choose option: ");
		scanf("%1d", &selectVar);

		switch (selectVar)
		{
			case 1:
			{
				WeekTemp week;
				break;
			}
			case 2:
			{
				for (int i = 0; i < 7; i++)
				{
					printf("Enter temperature for day %d: ", i + 1);
					scanf("%d",&newWeek[i]);
					getchar();		
				}
				week.loadWeek(newWeek);
				break;
			}
			case 3:
			{
				printf("Mean temperature: %.2f", week.meanTemp());
				break;
			}

			case 4:
			{
				printf("Median temperature: %d", week.medianTemp());
				break;
			}

			case 5:
			{
				printf("Standard deviation: %.2f", week.SD());
				break;
			}

			default:

				break;
		}
	}

	puts("Closing program...");

}
