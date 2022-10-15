/*
Name: Mads Richardt
Student ID: s224948
Assignment: a4_7.1
Date: 13/10/2022
*/

#include <stdio.h>

int main() {
	
	int counter = 0;
    	int n_new = 0;
    	int n_old = 1;
	while (1)
	{
		n_new = 2 * n_old;
		counter++;
        if (n_new == n_old)
        {
	counter--;
	break;
        }
		n_old = n_new;
	}
	
	printf("Number of bits in int: %d\n", counter);
		
	return 0;
}



