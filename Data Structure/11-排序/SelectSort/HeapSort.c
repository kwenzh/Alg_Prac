#include<stdio.h>

#include"../../include/KwenPrePareDatatools.h"

void heapSort(int *array, int array_length);
void adjustHeap(int *array, int count, int root);

void adjustHeap(int *array, int count, int root) {
	int leftChild;
	int rightChild;
	int whichChild;


	while(root <= count/2 - 1) {

		leftChild = 2 * root + 1;
		rightChild = ((leftChild + 1) >= count) ? -1 : (leftChild + 1);

		whichChild = (rightChild == -1) ? leftChild : (array[leftChild] > array[rightChild] ? leftChild : rightChild);
		whichChild = array[root] > array[whichChild] ? -1 : whichChild;

		if(-1 == whichChild) {
			return;
		}
		swapData(&array[root], &array[whichChild]);

		root = whichChild;
	}
}

//通过堆排序完成升序 先初始化大顶堆
//然后交换堆顶的和对重最后一个元素 继续维护大顶堆 不断去交换堆顶和队尾的元素
//把当前最大的元素放到队尾 完成升序
void heapSort(int *array, int array_length) {
	int root;

	for(root = array_length / 2 - 1; root >= 0; root--) {
		adjustHeap(array, array_length, root);
	}
	swapData(&array[0], &array[array_length - 1]);
	for(array_length--; array_length > 1; array_length--) {
		adjustHeap(array, array_length, 0);
		swapData(&array[0], &array[array_length - 1]);
	}
}


int main(void) {
	int array_length = 9;
	// int *array = createArray(array_length, 20 ,1);
	int array[] = {70,80,31,37,10,1,48,60,33};

	showArray(array, array_length);
	heapSort(array, array_length);
	showArray(array, array_length);

	// kwen_free(array);

	return 0;
}