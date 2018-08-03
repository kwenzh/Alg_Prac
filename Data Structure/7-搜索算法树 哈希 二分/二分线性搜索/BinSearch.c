#include<stdio.h>

#include"../../include/KWENARRAYTOOLS.h"

#define NOT_FOUND	-1

//二分查找
int BinarySearch(int *array, int array_lenigth, int targetValue);

// 插值查找 计算值
int InterploationSearch(int *array, int array_length, int targetValue);

void shellSort(int *array, int array_length);

int InterploationSearch(int *array, int array_length, int targetValue) {
	int min = 0;
	int max = array_length - 1;
	int times = 5;
	int index;

	if(targetValue > array[max] || targetValue < array[min]) {
		return NOT_FOUND;
	}

	while(min <= max) {
		double dert = ((double)targetValue - (double)array[min]) / ((double)array[max] - (double)array[min]);
		if(dert <= 0) {
			dert = 0;
		}
		index = min + dert * (double)(max - min);
		if(array[index] == targetValue) {
			return index;
		}

		array[index] < targetValue ? (min = index + 1) : (max = index  - 1);
	}

	return NOT_FOUND;
}

void shellSort(int *array, int array_length) {
	int i,j;
	int gap;

	for(gap = array_length / 2; gap > 0; gap /= 2) {
		for(i = gap; i < array_length; i++) {
			for(j = i - gap; j >= 0 && array[j] > array[j + gap]; j -= gap) {
				swapData(&array[j], &array[j + gap]);
			}
		}
	}
}


int BinarySearch(int *array, int array_length, int targetValue) {
	int a = 0;
	int b = array_length - 1;

	while(a <= b) {
		int middle = (a + b) / 2;
		if(array[middle] == targetValue) {
			return middle;
		}
		array[middle] < targetValue ? (a = middle + 1) : (b = middle - 1);
	}

	return -1;
}

int main(void) {
	int array[] = {15,20,24,30,75,78,82,94,99};
	int array_length = sizeof(array) / sizeof(int);
	int index;
	int targetValue = 21;
	int *array2 = NULL;

	// array2 = createArray(array_length, 100, 1);
	// shellSort(array, array_length);
	showArray(array, array_length);
	scanf("%d", &targetValue);
	index = InterploationSearch(array, array_length, targetValue);
	printf("index = %d\n", index);


	// destoryArray(&array2);

	return 0;
}
