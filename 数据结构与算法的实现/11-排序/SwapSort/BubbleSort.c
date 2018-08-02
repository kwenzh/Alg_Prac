#include<stdio.h>

#include"../../include/KwenPrePareDataTools.h"

//冒泡排序是稳定的排序算法
//气泡排序法
// 顾名思义，就是排序时，最大的元素会如同气泡一样移至右端，其利用比较相邻元素的方法，
// 将大的元素交换至右端，所以大的元素会不断的往右移动，直到适当的位置为止。
// 基本的气泡排序法可以利用旗标的方式稍微减少一些比较的时间，当寻访完阵列后都没有发生
// 任何的交换动作，表示排序已经完成，而无需再进行之后的回圈比较与交换动作，例如：
// 排序前：95 27 90 49 80 58 6 9 18 50
// 27 90 49 80 58 6 9 18 50 [95] 95浮出
// 27 49 80 58 6 9 18 50 [90 95] 90浮出
// 27 49 58 6 9 18 50 [80 90 95] 80浮出
// 27 49 6 9 18 50 [58 80 90 95] ...... 
// 27 6 9 18 49 [50 58 80 90 95] ...... 
// 6 9 18 27 [49 50 58 80 90 95] ...... 
// 6 9 18 [27 49 50 58 80 90 95] 
// 由于接下来不会再发生交换动作，排序提早结束
// 在上面的例子当中，还加入了一个观念，就是当进行至i与i+1时没有交换的动作，表示接下来的
// i+2至n已经排序完毕，这也增进了气泡排序的效率。
void ShakerSort(int *array, int array_length);

void BubbleSort(int *array, int array_length);

void BubbleSort(int *array, int array_length) {
	int i;
	int j;

	for(i = 0; i < array_length - 1; i++) {
		for(j = 0; j < array_length - i - 1; j++) {
			if(array[j] > array[j + 1]) {
				swapData(&array[j], &array[j + 1]);
			}
		}
	}
}

void ShakerSort(int *array, int array_length) {
	int i;
	int j;

	for(i = 0; i < array_length - 1; i++) {
		boolean hasSwapflag = 0;
		for(j = 0; j < array_length - i - 1; j++) {
			if(array[j] > array[j + 1]) {
				swap(&array[j], &array[j + 1]);
				hasSwapflag = 1;
			}
		}
		if(!hasSwapflag) {
			break;
		}
	}
}

int main(void) {
	int *array;
	int array_length = 20;
	int maxValue = 1000000;
	int minValue = 1;

	array = createArray(array_length, maxValue, minValue);
	showArray(array, array_length);
	BubbleSort_high(array, array_length);
	showArray(array, array_length);

	free(array);
}