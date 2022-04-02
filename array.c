#include <stdio.h>
#include "array.h"

void print_array(int* arr, int size) {

	printf("[ ");
	for (int i = 0; i < size; i++) {

		printf("%d ", arr[i]);
	}
	printf(" ]\n");
}

int get_sum_of_array(int* arr, int size) {

	int sum = 0;

	for (int i = 0; i < size; i++) {

		sum += arr[i];
	}
	return sum;
}