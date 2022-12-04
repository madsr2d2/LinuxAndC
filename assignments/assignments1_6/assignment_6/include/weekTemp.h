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