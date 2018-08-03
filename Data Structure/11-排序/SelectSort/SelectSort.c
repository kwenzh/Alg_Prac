#include<stdio.h>
#include"../../include/KWENARRAYTOOLS.h"

/*
选择排序
将要排序的对象分作两部份，一个是已排序的，一个是未排序的，从后端未排序部份选择一个
最小值，并放入前端已排序部份的最后一个，例如：
排序前：70 80 31 37 10 1 48 60 33 80
[1] 80 31 37 10 70 48 60 33 80 选出最小值1
[1 10] 31 37 80 70 48 60 33 80 选出最小值10
[1 10 31] 37 80 70 48 60 33 80 选出最小值31
[1 10 31 33] 80 70 48 60 37 80 ......
[1 10 31 33 37] 70 48 60 80 80 ......
[1 10 31 33 37 48] 70 60 80 80 ......
[1 10 31 33 37 48 60] 70 80 80 ......
[1 10 31 33 37 48 60 70] 80 80 ......
[1 10 31 33 37 48 60 70 80] 80 ......
 选择排序不是稳定的排序 */
void selectedSort(int *array, int array_length);

void selectedSort(int *array, int array_length) {
	int i;
	int j;
	int min;

	for(i = 0; i <  array_length; i++) {
		min = i;
		for(j = i; j < array_length; j++) {
			min = array[j] < array[min] ? j : min;
		}
		if(min != i) {
			swapData(&array[i], &array[min]);
		}

	}
}

int main(void) {
	int *array;
	int array_length = 10;

	array = createArray(array_length, 30,1);

	showArray(array, array_length);
	selectedSort(array, array_length);
	showArray(array, array_length);

	return 0;
}
