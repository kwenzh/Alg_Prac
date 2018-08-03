// 未完成 一点想法
#ifndef _HASH_TABLE_H_
#define _HASH_TABLE_H_

#define MAXSIZE			1 << 31

#define true			1
#define false			0

typedef unsigned char boolean;

typedef int DataType;

typedef struct LinkList {
	void *data;
	struct LinkList *next;
}LinkList;

typedef struct HASHTABLEHEAD {
	double LoadFactor;			//负载因子 一旦哈希表里面槽占用比例超过这个 就需要进行扩容
	int hashMaxLoad;          	//哈希槽的总数
	int hashSize;				//已经放元素的哈希槽的个数
	struct HASHTABLE *hashTable;//指向实际的哈希表
}HASHTABLEHEAD;

typedef struct HASHTABLE {
	boolean addressTemp;
	DataType value;
	LinkList *head;				//用来解决发生哈希碰撞了的元素
	int collisionCount;			//记录每个哈希槽发生哈希碰撞元素的个数 也就是链表的长度
}HASHTABLE;

/*
实现一种自动扩容的哈希表 给定初始容量最大容量为 1 <<31
问题的难点在于扩容时候的搬运元素
KWENHASHTABLE *hashHead;
hashHead = (KWENHASHTABLE *)malloc(sizeof(KWENHASHTABLE));
hashHead->hashTable = (HASHTABLE *)calloc(sizeof(HASHTABLE), hashMaxLoad);
hashHead->hashSize = 0;
hashHead->hasMaxLoad = 16;
hashHead->LoadFactor = 0.75;
需要扩容的时候先申请一个更大的空间
temp = hashHead->hashMaxLoad;
hashHead->hashMaxLoad < 1<<31 && hashHead->hashMaxLoad <<= 1 ;
HASHTABLE *array = (HASHTABLE *)calloc(sizeof(HASHTABLE), hashHead->hashMaxLoad);
for(i = 0; i < temp; i++) {
	if(hashHead->hashTable[i].addressTemp == false) {
		array[i] = hashHead->hashTable[i];
	}
}
free(hashHead->hashTable);
hashHead->hashTable = array;
*/

#endif
