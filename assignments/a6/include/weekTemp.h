#ifndef WEEKTEMP
#define WEEKTEMP

#include <algorithm>
#include <cmath>
#include  <stdio.h>
using namespace std;

// WeekTemp class
class WeekTemp {
    private:
        int weekTemps[7];
        int sortedWeekTemps[7];

    public:
        // Constructor.
        WeekTemp()
        {
            int demoWeek[] = {18, 16, 14, 13, 14, 17, 17};
            copy(begin(demoWeek), end(demoWeek), weekTemps);
            copy(begin(demoWeek), end(demoWeek), sortedWeekTemps);
            sort(sortedWeekTemps, sortedWeekTemps + 7);
        }
        
        // Load week function.
        int loadWeek(int *weekTempArr)
        {
            int i;
            for (i = 0; i < 7; i++)
            {
                weekTemps[i] = weekTempArr[i];
            }
            copy(begin(weekTemps), end(weekTemps), sortedWeekTemps);
            sort(sortedWeekTemps, sortedWeekTemps + 7);
            return i;
        }

        // Function to compute mean temperature.
        float meanTemp()
        {
            int sum = 0;
            for (int i = 0; i < 7; i++)
            {
                sum += weekTemps[i];
            }
            return sum/7.0;
        }

        // Function to compute median temperature.
        int medianTemp()
        {
            return sortedWeekTemps[3];
        }

        // Function to compute the standard deviation.
        float SD()
        {
            float variance = 0;
            float mean = meanTemp();

            for (int i = 0; i < 7; i++)
            {
                variance += (weekTemps[i] - mean) * (weekTemps[i] - mean);
            }
            
            return sqrt(variance/7);
        }

        // Returns a pointer to a copy of WeekTemps in heap.
        int *getWeek()
        {
            int *weekTempsCopy = (int*)malloc(7*sizeof(int));
            copy(begin(weekTemps), end(weekTemps), weekTempsCopy);
            return weekTempsCopy;
        }
};

#endif
