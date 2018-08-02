#include<stdio.h>

#include"../../include/KwenPrePareDataTools.h"
/*
插入排序
像是玩朴克一样，我们将牌分作两堆，每次从后面一堆的牌抽出最前端的牌，然后插入前面一
堆牌的适当位置，例如：
排序前：92 77 67 8 6 84 55 85 43 67
[77 92] 67 8 6 84 55 85 43 67 将77插入92前
[67 77 92] 8 6 84 55 85 43 67 将67插入*77前
[8 67 77 92] 6 84 55 85 43 67 将8插入67前
[6 8 67 77 92] 84 55 85 43 67 将6插入8前
[6 8 67 77 84 92] 55 85 43 67 将84插入92前
[6 8 55 67 77 84 92] 85 43 67 将55插入67前
[6 8 55 67 77 84 85 92] 43 67 ......
[6 8 43 55 67 77 84 85 92] 67 ......
[6 8 43 55 67 67 77 84 85 92] 
 */
//插入排序是稳定的排算法
void DirectInsertSorted(int *array, int array_length);

void DirectInsertSorted(int *array, int array_length) {
	int i;
	int j;
	int t;
	int temp;

	for(i = 1; i < array_length; i++) {
		temp = array[i];
		for(j = 0; j < i && array[j] <= array[i]; j++);
		for(t = i; t > j; t--) {
			array[t] = array[t - 1];
		}
		array[t]  = temp;
	}
}

int main(void) {
	int *array;
	int array_length = 10;

	array = createArray(array_length, 30,1);

	showArray(array, array_length);
	DirectInsertSorted(array, array_length);
	showArray(array, array_length);

	return 0;
}