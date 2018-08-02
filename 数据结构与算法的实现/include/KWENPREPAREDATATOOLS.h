#ifndef _KWEN_PREPARE_DATA_TOOLS_H_
#define _KWEN_PREPARE_DATA_TOOLS_H_

#ifndef _MALLOC_KWEN_SORT_H
#define _MALLOC_KWEN_SORT_H
#include<malloc.h>
#include<time.h>
#endif

#include"KWENBASE.h"

#define NOT_NODE_INDEX		-1

//准备一个数组 长度为count，范围在minValue-maxValue之间
int *createArray(int count, int maxValue, int minValue);

void showArray(int *array, int count);

void showArrayAddress(int *array, int array_length);

void kwen_free(int *data);

void kwen_free(int *data) {
	free(data);
	data = NULL;
}

void showArrayAddress(int *array, int array_length) {
	int i;

	for(i = 0; i < array_length; i++) {
		printf("%p ", &array[i]);
	}

	printf("\n");
}

void showArray(int *array, int count) {
	int index;

	for(index = 0; index < count; index++) {
		printf("%d ", array[index]);
	}
	printf("\n");
}

int *createArray(int count, int maxValue, int minValue)  {
	int *result = NULL;
	int index = 0;

	result = (int *)calloc(sizeof(int), count);

	srand(time(NULL));
	for(index = 0; index < count; index++) {
		result[index] = rand()%(maxValue - minValue + 1) + minValue;
	}

	return result;
}

#endif
