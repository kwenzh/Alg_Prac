#include<stdio.h> 
#include<limits.h>

#include"../../include/KwenPrePareDataTools.h"

void shellSort(int *array, int array_length);


void shellSort(int *array, int array_length) {
	int i,j;
	int gap;

	for(gap = array_length / 2; gap > 0; gap /= 2) {
		for(i = gap; i < array_length; i++) {
			for(j = i - gap; j >= 0 && array[j] > array[j + gap]; j -= gap) {
				swapData_way1(&array[j], &array[j + gap]);
				showArray(array, array_length);
			}
		}
	}
}

int main(void) {
	int *array;
	int array_length = 9;

	array = createArray(array_length, 30,1);

	showArray(array, array_length);
	shellSort(array, array_length);
	showArray(array, array_length);

	return 0;
}