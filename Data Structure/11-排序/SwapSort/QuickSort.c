#include<stdio.h>

#include"../../include/KWENARRAYTOOLS.h"

//快速排序不是稳定的排序算法
void quickSort(int *array, int array_length);

/*
解法这边所介绍的快速演算如下：将最左边的数设定为轴，并记录其值为 s
廻圈处理：
令索引 i 从数列左方往右方找，直到找到大于 s 的数
令索引 j 从数列左右方往左方找，直到找到小于 s 的数
如果 i >= j，则离开回圈d
如果 i < j，则交换索引i与j两处的值
将左侧的轴与 j 进行交换
对轴左边进行递回
对轴右边进行递回
说明在快速排序法（一）中，每次将最左边的元素设为轴，而之前曾经说过，快速排序法的
加速在于轴的选择，在这个例子中，只将轴设定为中间的元素，依这个元素作基准进行比较，
这可以增加快速排序法的效率。
解法在这个例子中，取中间的元素s作比较，同样的先得右找比s大的索引 i，然后找比s小的
索引 j，只要两边的索引还没有交会，就交换 i 与 j 的元素值，这次不用再进行轴的交换了，
因为在寻找交换的过程中，轴位置的元素也会参与交换的动作，例如：
41 24 76 11 45 64 21 69 19 36
首先left为0，right为9，(left+right)/2 = 4（取整数的商），所以轴为索引4的位置，比较的元素是
45，您往右找比45大的，往左找比45小的进行交换：
41 24 76* 11 [45] 64 21 69 19 *36
41 24 36 11 45* 64 21 69 19* 76
41 24 36 11 19 64* 21* 69 45 76
[41 24 36 11 19 21] [64 69 45 76]
完成以上之后，再初别对左边括号与右边括号的部份进行递回，如此就可以完成排序的目的。
 */
void quickSortOnce(int *array, int left, int right);

void quickSortOnce(int *array, int left, int right) {
	int i;
	int j;
	int s;
	static int count = 0;

	if(left < right) {
		s = array[(left + right) / 2];
		i = left - 1;
		j = right + 1;
		while(1) {
			while(array[++i] < s);
			while(array[--j] > s);
			if(i >= j){
				break;
			}
			swapData(&array[i], &array[j]);
		}
		printf("for %dth time quickSort: mid = %d, low = %d, high = %d  ", ++count, s, i , j);
		showArray(array, 9);
		quickSortOnce(array, left, i - 1);// 对停止循环后i的左右进行递归
		quickSortOnce(array, j + 1, right);	//对j的右侧进行递归
	}
}

void quickSort(int *array, int array_length) {
	quickSortOnce(array, 0, array_length - 1);
}

int main(void) {
	int array[] = {70,80,31,37,10,1,48,60,33};
	int array_length = 9;
	int maxValue = 20;
	int minValue = 1;

	// array = createArray(array_length, maxValue, minValue);
printf("After sorted data:\n");
	showArray(array, array_length);
printf("sorting data:\n");
	quickSort(array, array_length);
printf("Finished sorted data : \n");
	showArray(array, array_length);

	kwen_free(array);

	return 0;
}
