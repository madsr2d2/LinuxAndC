/*
Mandatory assignment: 4
Lesson: 8
Student name: Mads Richardt
Student Id: s224948
Date: 20/10/2022

************
Exercise 8.1
************
	Answer: 
		D. *p = 75
*/

#include <stdio.h>

void swap(int *,int *);
void foo1(int);
void foo2(int);

int main() {
	int select_var;

	// Select exercise
	printf("1: Swap\n2: StackAllocation\nPlease select option: ");
	scanf("%d", &select_var);

	// Exercise 8.2
	if (select_var == 1) {	
		puts("\n****");
		puts("Swap");
		puts("****");
		int x = 1;
		int y = 2;
		puts("Variable values before swap was called");
		printf("x = %d, y = %d\n",x,y);
		// Call swap
		swap( &x, &y);
		puts("Variable values after swap was called");
		printf("x = %d, y = %d\n",x,y);
	}

	if (select_var == 2) {
		puts("\n***************");
		puts("StackAllocation");
		puts("***************");
		foo1(7);
		foo2(11);
	}
	return (0);
}

void swap(int *x, int *y) {
	int temp = *y;
	*y = *x;
	*x = temp;
} 

void foo1 (int xval) {
	int x;
	x = xval;
	printf("Value of x = %d\nAddress of x = %p\n", x, &x);
}

void foo2(int dummy) {
	int y;
	printf("Value of y = %d\nAddress of y = %p\n", y, &y);
}