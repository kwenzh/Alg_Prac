#include<stdio.h>

#include"../../include/KWENPREPAREDATATOOLS.h"

//计数排序主要思想是将待排序序列的值当做下标，在另外一个数组中进行统计
//有类似统计一段字符串中各个字符出现的频率，也是空间换时间的思想
//新申请的数组长度是待排序序列中max-min+1，min当做一个偏移量
//计数排序对于待排序序列数值分布在小范围有很好的效果，前提是整数，这很关键，浮点数无法去寻找下标，除非放大浮点数

//主要是找出数组array中的最大值最小值，传递countSort_Tool函数去申请空间
void countSort(int *array, int array_length);

void countSort_Tool(int *array, int array_length, int maxValue, int minValue);

void countSort_Tool(int *array, int array_length, int maxValue, int minValue) {
	int *countArray;
	int countArray_length = maxValue - minValue + 1;
	int i;
	int index = 0;

	countArray = (int *)calloc(sizeof(int), countArray_length);
	//进行计数 注意有一个偏移量minvalue
	for(i = 0; i < array_length; i++) {
		countArray[array[i] - minValue]++;
	}

	for(i = 0; i < countArray_length; i++) {
		while(countArray[i] > 0) {
			array[index++] = i + minValue;
			countArray[i]--;
		}
	}

	kwen_free(countArray);
}

void countSort(int *array, int array_length) {
	int max;
	int min;
	int i;

	for(i = 1, max = array[0], min = array[0]; i < array_length; i++) {
		max = max > array[i] ? max : array[i];
		min = min < array[i] ? min : array[i];
	}

	countSort_Tool(array, array_length, max, min);

}

int main(void) {
	int *array;
	int array_length = 10;

	array = createArray(array_length, 100, 0);

	showArray(array, array_length);
	countSort(array, array_length);
	showArray(array, array_length);

	kwen_free(array);

	return 0;
}
