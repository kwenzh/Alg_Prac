#ifndef _KWEN_SORT_TOOLS_H_
#define _KWEN_SORT_TOOLS_H_

#include<stdio.h>

#include"../../include/KWENLINKLISTTOOLS.h"
#include"../../include/KWENARRAYTOOLS.h"

#ifndef _QUICK_SORT_KWEN_SORT_
#define _QUICK_SORT_KWEN_SORT_
void quickSortOnce(int *array, int left, int right);
/*快速排序不是一种稳定的排序算法，快速排序将数组分成两部分并递归调用自身的方式进行排序
开始分的时候取头尾的中间值s，并给出两个索引i，j，
令索引 i 从数列左方往右方找，直到找到大于 s 的数
令索引 j 从数列左右方往左方找，直到找到小于 s 的数
然后交换a[i], a[j],知道i和j相遇或者i跨过了j就停止这次的寻找，开始递归轴的左端和右端
quickSortOnce(array, left, i - 1);
quickSortOnce(array, j + 1, right);
 */
void quickSort(int *array, int array_length);
#endif

#ifndef _DIRECT_SELECT_SORT_KWEN_SORT_
#define _DIRECT_SELECT_SORT_KWEN_SORT_
void selectedSort(int *array, int array_length);
#endif

#ifndef _HEAP_SORT_KWEN_SORT_H
#define _HEAP_SORT_KWEN_SORT_H
void heapSort(int *array, int array_length);
void adjustHeap(int *array, int count, int root);
#endif

#ifndef _SHELL_SORT_KWEN_SORT_
#define _SHELL_SORT_KWEN_SORT_
void shellSort(int *array, int array_length);
#endif

#ifndef _DIRECT_INSERT_SORT_KWEN_SORT_
#define _DIRECT_INSERT_SORT_KWEN_SORT_
void DirectInsertSorted(int *array, int array_length);
#endif

#ifndef _BUBBLE_SORT_KWEN_SORT_
#define _BUBBLE_SORT_KWEN_SORT_
void BubbleSort_high(int *array, int array_length);
void BubbleSort_low(int *array, int array_length);
#endif

#ifndef _MERGE_SORT_KWEN_SORT_
#define _MERGE_SORT_KWEN_SORT_
void mergeArray(int *array1, int first, int mid, int last, int *array2);
void Divided(int *array1, int first, int last, int *array2);
/*
归并排序相比堆排序，快排更容易理解，先是对数组不断划分直到每个区间只有一个元素，
那么就认为这一个元素是有序的，划分完毕后开始逐步合并两个有序的数组成一个有序数组
需要申请新的同样大的内存空间
{16,2,1,5,14,2,3,5} 开始划分
{{16,2,1,5},{14,2,3,5}}
{{{16,2},{1,5}},{{14,2},{3,5}}}
{{{{16}{2}},{{1}{5}}},{{{14}{2}},{{3}{5}}}}开始合并
{{{2,16},{1,5}},{{2,14},{3,5}}}
{{1,2,5,16},{2,3,5,14}}
{1,2,2,3,5,5,14,16}
 */

void MergeSort(int *array, int array_length);
#endif

#ifndef _BUCKET_SORT_KWEN_SORT_
#define _BUBBLE_SORT_KWEN_SORT_
typedef struct BUCKET{
	int count;
	struct LinkList *list;
}BUCKET;
//记住bucket只是一个结构体数组
void destoryBucket(BUCKET *bucket, int BucketCount);
void initBucket(BUCKET *bucket, int BucketCount);
void insertDataToBucket(int *array, int array_length, BUCKET *bucket, int minValue);
void BucketDataToArray(int *array, int array_length, BUCKET *bucket, int BucketCount);
void BUCKETSORT(int *array, int array_length);
#endif

#ifndef _COUNT_SORT_KWEN_SORT_
#define _COUNT_SORT_KWEN_SORT_
//计数排序
void countSort(int *array, int array_length);

//计数排序的缺点在于只能处理整数范围内的数据，用空间换来了时间，擅长处理很多重复的数据
////计数排序主要思想是将待排序序列的值当做下标，在另外一个数组中进行统计
//有类似统计一段字符串中各个字符出现的频率，也是空间换时间的思想
//新申请的数组长度是待排序序列中max-min+1，min当做一个偏移量
//计数排序对于待排序序列数值分布在小范围有很好的效果，前提是整数，这很关键，浮点数无法去寻找下标，除非放大浮点数
//主要是找出数组array中的最大值最小值，传递countSort_Tool函数去申请空间
void countSort_Tool(int *array, int array_length, int maxValue, int minValue);
#endif


#ifndef _ALL_SORT_NAME_KWEN_SORT_
#define _ALL_SORT_NAME_KWEN_SORT_
void allsort(int *array, int array_length, int whichSort);
#endif

#ifndef _SORT_FUNCTION_MERGE_KWEN_SORT_
#define _SORT_FUNCTION_MERGE_KWEN_SORT_
typedef void (*SortFunction)(int *, int);
#endif

const SortFunction ALLSORT[] = {
	quickSort,
	MergeSort,
	heapSort,
	shellSort,
	countSort,
	// BUCKETSORT,
	selectedSort,
	DirectInsertSorted,
	BubbleSort_high,
	BubbleSort_low
};

const char* sortName[] = {
	"QuickSort",
	"MergeSort",
	"HeapSort",
	"ShellSort",
	"countSort",
	// "BUCKETSORT",
	"SelectedSort",
	"InsertSort",
	"BubbleSort_high",
	"BubbleSort_low"
};

const int ALLSORT_LENGTH = sizeof(ALLSORT) / sizeof(SortFunction);

#ifndef _SORT_COMPARE_H_
#define _SORT_COMPARE_H_

void BucketDataToArray(int *array, int array_length, BUCKET *bucket, int BucketCount) {
	int index = 0;
	int i;
	LinkList *p;

	for(i = 0; i < BucketCount && index < array_length; i++) {
		p = bucket[i].list->next;
		while(p != NULL) {
			array[index++] = p->data;
			p = p->next;
		}
	}
}

void insertDataToBucket(int *array, int array_length, BUCKET *bucket, int minValue) {
	int i;
	int index;
	LinkList *p;

	for(i = 0; i < array_length; i++) {
		LinkList *node;
		index = (array[i] - minValue) / array_length;
		p = bucket[index].list;    //每次让p指向当前桶的头结点
		node = (LinkList *)calloc(sizeof(LinkList), 1);
		node->data = array[i];
//将数组的数据升序的放进链表 考虑链表是否为空
//为空的话直接放在头结点后面
//不为空的话需要找要插入位置的前驱节点
		if(bucket[index].count == 0) {
			node->next = p->next;
			p->next = node;
		}else {
			p = (array[i] > (p->next->data)) ? p->next : p;
			//如果此时一个桶是H->6，让5进桶，此时p还是指向head，
			//如果5大于头结点的下一个节点值，再让p移动 不然的话p不懂还是指向头
			//进入下面循环后发现5不大于6 p也没有移动还是在头结点 插入5到头结点后面
			while(p->next && (array[i] > p->next->data)) {
				p = p->next;
			}
			node->next = p->next;
			p->next = node;
		}
		bucket[index].count++;
	}
}

void initBucket(BUCKET *bucket, int BucketCount) {
	int i;

	for(i = 0; i < BucketCount; i++) {
		bucket[i].count = 0;
		initLinkList(&(bucket[i].list));
	}
}

void destoryBucket(BUCKET *bucket, int BucketCount) {
	int i;

//销毁每一个桶里面的链表
	for(i = 0; i < BucketCount; i++) {
		// showListInfor(bucket[i].list);
		destoryLinkList(&(bucket[i].list));
	}

	free(bucket);
	bucket = NULL;
}

void BUCKETSORT(int *array, int array_length) {
	int BucketCount;
	int maxValue;
	int minValue;
	BUCKET *bucket;

	maxValue = getArrayMaxValue(array, array_length);
	minValue = getArrayMinValue(array, array_length);

	BucketCount = (maxValue - minValue + array_length) / array_length;
	bucket = (BUCKET *)calloc(sizeof(BUCKET), BucketCount);

	initBucket(bucket, BucketCount);
	insertDataToBucket(array, array_length, bucket, minValue);
	BucketDataToArray(array, array_length, bucket, BucketCount);

	destoryBucket(bucket, BucketCount);
}

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

	destoryArray(&countArray);
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

//二路归并排序
void Divided(int *array1, int first, int last, int *array2) {
	if(first < last) {
		int mid = (first + last) / 2;
		Divided(array1, first, mid, array2);
		Divided(array1, mid + 1, last, array2);
		mergeArray(array1, first, mid, last, array2);
	}
}

void mergeArray(int *array1, int first, int mid, int last, int *array2) {
	int i = first;
	int j = mid + 1;
	int m = mid;
	int n = last;
	int k = 0;

	while(i <= m && j <= n) {
		array2[k++] = array1[i] <= array1[j] ? array1[i++] : array1[j++];
	}

	while(i <= m) {
		array2[k++] = array1[i++];
	}
	while(j <= n) {
		array2[k++] = array1[j++];
	}

	for(i = 0; i < k; i++) {
		array1[first + i] = array2[i];
	}
}

void MergeSort(int *array, int array_length) {
	int *array2;

	array2 = (int *)calloc(sizeof(int), array_length);
	Divided(array, 0, array_length - 1, array2);

	free(array2);
}


void allsort(int *array, int array_length, int whichSort) {
	if(whichSort < 0 || whichSort >= ALLSORT_LENGTH) {
		return;
	}

	ALLSORT[whichSort](array, array_length);
}

void BubbleSort_low(int *array, int array_length) {
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

void BubbleSort_high(int *array, int array_length) {
	int i;
	int j;

	for(i = 0; i < array_length - 1; i++) {
		boolean hasSwapflag = 0;
		for(j = 0; j < array_length - i - 1; j++) {
			if(array[j] > array[j + 1]) {
				swapData(&array[j], &array[j + 1]);
				hasSwapflag = 1;
			}
		}
		if(!hasSwapflag) {
			break;
		}
	}
}

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

void heapSort(int *array, int array_length) {
	int root;
	int temp;

	for(root = array_length / 2 - 1; root >= 0; root--) {
		adjustHeap(array, array_length, root);
	}
	swapData(&array[0], &array[array_length - 1]);

	temp = array_length;
	for(temp--; temp > 1; temp--) {
		adjustHeap(array, temp, 0);
		swapData(&array[0], &array[temp - 1]);
	}

}
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

void quickSortOnce(int *array, int left, int right) {
	int i;
	int j;
	int s;

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
		quickSortOnce(array, left, i - 1);// 对停止循环后i的左右进行递归
		quickSortOnce(array, j + 1, right);	//对j的右侧进行递归
	}
}

void quickSort(int *array, int array_length) {
	quickSortOnce(array, 0, array_length - 1);
}

#endif
#endif
