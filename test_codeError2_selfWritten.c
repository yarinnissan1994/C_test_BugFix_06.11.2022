#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable : 4996)

void task1_triangle(int base, int height) {
	printf("triangle base = %d\n", base);
	printf("triangle height = %d\n", height);
	float TriangleArea = base * height / 2;
	printf("triangle area = %f\n", TriangleArea);
}

void task2_staticArray() {
	int array[6];
	for (int i = 0; i < 6; i++)
	{
		array[i] = i + 1;
	}
	for (int i = 0; i < 6; i++)
	{
		printf("%d", array[i]);
		if (i != 5)
		{
			printf(" -> ");
		}
	}
	printf("\n");
}

void taks3_dynamicArray() {
	int* arrPtr = (int*)malloc(sizeof(int) * 6);
	int* rootPtr = arrPtr;
	if (arrPtr == NULL)
	{
		printf("failed to allocate memory");
		return;
	}
	for (int i = 0; i < 6; i++)
	{
		*arrPtr = i + 1;
		arrPtr++;
	}
	arrPtr = rootPtr;
	for (int i = 0; i < 6; i++)
	{
		printf("%d", *arrPtr);
		if (i != 5)
		{
			printf(" -> ");
			arrPtr++;
		}
	}
	printf("\n");
	free(rootPtr);


}

int main22() {
	task1_triangle(10, 3);
	task2_staticArray();
	taks3_dynamicArray();
	return 0;
}