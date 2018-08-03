#include<stdio.h>

#include"../../include/KWENLINKLISTTOOLS.h"
#include"../../include/KWENARRAYTOOLS.h"


// 桶由链表和数组构成  count负责记录这个桶由几个元素 也就是链表的长度
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


int main(void) {
	int *array;
	int array_length = 10000;
	long before_time;
	long end_time;
	long total_time;


	array = createArray(array_length, 1000000 , 1);
	// showArray(array, array_length);
before_time = clock();
	BUCKETSORT(array, array_length);
end_time = clock();
total_time = end_time - before_time;
	// showArray(array, array_length);
printf("%ld.%03ld s\n", total_time / 1000, total_time % 1000);

	destoryArray(&array);

	return 0;
}
