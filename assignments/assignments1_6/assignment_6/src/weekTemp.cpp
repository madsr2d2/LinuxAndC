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