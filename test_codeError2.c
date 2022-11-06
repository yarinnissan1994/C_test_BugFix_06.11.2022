#include <stdio.h>
#include <stdlib.h>
int main2()
{
	int x, y;
	int nums[6];
	int* arrPtr;

	// Section A - Print the variables
	// bug - trying to print uninitialized variables (x, y)
	x = 7; // fix - initialized x
	y = 3; // fix - initialized y
	puts("***** Section A *****");
	printf(" Base = %d\n", x);
	printf(" Height = %d\n", y);
	//printf(" Area = %d\n", x * y); // bug - Incorrect equation for calculating the area of ​​a triangle
	printf(" Area = %d\n", (x * y / 2)); // fix - correct equation for calculating the area of ​​a triangle

	// Section B - Print the static array "nums".

	//puts("***** Section B *****");
	//int i = 0;
	//while (i < 6) { bug - stop condition dosent executed - infinite loop
	//	printf(" nums[%d] = %d\n", i, nums[i]); // bug - uninitialized array print
	//}

	puts("***** Section B *****");
	int i = 0;
	while (i < 6) {
		nums[i] = i + 1; // fix - adding values to array
		printf(" nums[%d] = %d\n", i, nums[i]);
		i++; // fix - Fixing the variable related to the stopping condition
	}

	// Section C - Print allocated array.

	//puts("***** Section C *****");
	//arrPtr = malloc(sizeof(int) * 10); // bug - need to cast malloc void* to int*
	// bug - needs to save original ptr for freeing using array 
	//if (arrPtr) {
	//	for (i = 0; i < 6; i++) { // bug - dynamic array is empty from values
	//		printf(" array[%d] = %d\n", i, arrPtr[i]); // bug - printing array in incorrect syntax
	// bug - missing ptr running on array
	//	}
	// bug - not freeing memory allocation
	//}
	//else {
	//	printf("Error Allocating Memory!\n");
	//	exit(1);
	//}

	puts("***** Section C *****");
	arrPtr = (int*)malloc(sizeof(int) * 10); // fix - added casting for void* to int*
	int* rootPtr = arrPtr; // fix - adding root ptr
	if (arrPtr) {
		for (int i = 0; i < 6; i++)  // fix - initialazetion of array values
		{
			*arrPtr = i + 1;
			arrPtr++;
		}
		arrPtr = rootPtr;
		for (i = 0; i < 6; i++) {
			printf(" array[%d] = %d\n", i, *arrPtr); // fix - change syntax fro arrPtr[i] to *arrPtr for printing array values
			arrPtr++; // fix - change poiner position
		}
		free(rootPtr); // fix - freeing memory allocation
	}
	else {
		printf("Error Allocating Memory!\n");
		exit(1);
	}
	return 0;
}