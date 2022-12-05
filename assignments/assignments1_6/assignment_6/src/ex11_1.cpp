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