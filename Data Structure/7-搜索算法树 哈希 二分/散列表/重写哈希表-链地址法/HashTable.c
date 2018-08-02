#include<stdio.h>
#include<malloc.h>

#define HASHTABLESIZE	20
#define true			1
#define false			0

typedef unsigned char boolean;

typedef int DataType;

typedef struct LinkList {
	DataType data;
	struct LinkList *next;
}LinkList;

typedef struct HASHTABLE {
	boolean addressTemp;
	DataType value;
	LinkList *head;				//用来解决发生哈希碰撞了的元素
	int collisionCount;			//记录每个哈希槽发生哈希碰撞元素的个数 也就是链表的长度
}HASHTABLE;

void createHashTable(DataType*, int, HASHTABLE*);

boolean putDataToHashTable(DataType, HASHTABLE*);

//取余构造哈希函数 
int Hash(DataType);

boolean dealCollision(int, DataType, HASHTABLE *);

void destoryHashTable(HASHTABLE **);

boolean removeKeyWord(HASHTABLE *, DataType);

boolean containsKeyword(HASHTABLE *, DataType);

void showHashTable(HASHTABLE *);

//哈希表里面是否存在此关键字targetData
boolean containsKeyword(HASHTABLE *hashTable, DataType targetData) {
	int address = Hash(targetData);

	if(hashTable[address].addressTemp == true) {
//不存在此关键词		
		return false;
	}

	if(hashTable[address].value == targetData) {

		return true;
	}else {
		LinkList *p = hashTable[address].head->next;
		while(p != NULL && p->data != targetData) {
			p = p->next;
		}

		return p == NULL ? false : true;
	}
}

//由于使用链地址法解决的哈希碰撞 
//从哈希表中删除一个关键字项的时候 如果直接将该哈希槽处的值置为空
//那么在打印的时候 会带来一系列的问题 需要考虑链表是否还有元素
//有元素的话 就把链表第一个元素放进来 删除一个链表结点
boolean removeKeyWord(HASHTABLE *hashTable, DataType targetData) {
	int address = Hash(targetData);

	if(hashTable[address].addressTemp == true) {
		printf("keyword %d is not exist hashTable\n", targetData);
		return false;
	}

	if(hashTable[address].head->next == NULL) {
		hashTable[address].addressTemp = true;
	}else {
		LinkList *temp = hashTable[address].head->next;
		hashTable[address].value = temp->data;
		hashTable[address].head->next = temp->next;
		free(temp);
	}

	return true;

}


void showHashTable(HASHTABLE *hashTable) {
	int i;
	LinkList *p;

	for(i = 0; i < HASHTABLESIZE; i++) {
		if(hashTable[i].addressTemp == false) {
			printf("hash= %d: %d ",i, hashTable[i].value);
			if(hashTable[i].head != NULL) {
				p = hashTable[i].head->next;
				while(p != NULL) {
					printf("%d ", p->data);
					p = p->next;
				}
				printf("\n");
			}
		}	
	}
	printf("\n");

}


void destoryHashTable(HASHTABLE **hashTable) {
	int i;
	LinkList *temp;
	HASHTABLE *list = *hashTable;

	for(i = 0; i < HASHTABLESIZE; i++) {
		while(list[i].head != NULL) {
			temp = list[i].head;
			list[i].head = list[i].head->next;
			free(temp);
		}
		free(list[i].head);
		list[i].head = NULL;
	}

}

boolean dealCollision(int hashIndex, DataType data, HASHTABLE* hashTable) {
	// 以头插法的放入放入到这个哈希槽中的链表去 在插入数据应该先判断是否存在这个元素
	LinkList *p = hashTable[hashIndex].head->next;
	LinkList *node;

	while(p != NULL && p->data != data) {
		if(data == p->data) {
			return false;
		}
	}
	node = (LinkList *)calloc(sizeof(LinkList), 1);
	node->data = data;
	node->next = hashTable[hashIndex].head->next;
	hashTable[hashIndex].head->next = node;
	hashTable[hashIndex].collisionCount++;

	return true;
}

int Hash(DataType data) {
	return data % HASHTABLESIZE;
}


boolean putDataToHashTable(DataType data, HASHTABLE* hashTable) {
	int hashIndex = Hash(data);

	if(hashTable[hashIndex].addressTemp == true) {
		hashTable[hashIndex].value = data;
		hashTable[hashIndex].addressTemp = false;

		return true;
	}else {
//说明产生了哈希碰撞 data不同但是hashIndex相同 映射到同一个哈希槽里面 直 
		if(hashTable[hashIndex].value == data) {
// 关键字相同
			return false;
		}else {
			boolean insertResult = dealCollision(hashIndex, data, hashTable);
			if(insertResult == false) {
				printf("warning : keyword %d had existed hashTable\n", data);
			}

			return insertResult;
		}
	}
}


void createHashTable(DataType *array, int array_length, HASHTABLE *hashTable) {
	int i;

	for(i = 0; i < HASHTABLESIZE; i++) {
		hashTable[i].addressTemp = true;
		hashTable[i].collisionCount = 0;
		hashTable[i].head = (LinkList *)calloc(sizeof(LinkList), 1);
		hashTable[i].head->next = NULL;
	}

	for(i = 0; i < array_length; i++) {
		insertDataToHashTable(array[i], hashTable);
	}
}

int main(void) {
	DataType array[] = {2,3,4,65,23,54,12,24,25};
	int array_length = sizeof(array) / sizeof(DataType);
	HASHTABLE *hashTable = NULL;

	hashTable = (HASHTABLE *)calloc(sizeof(HASHTABLE), HASHTABLESIZE);
	createHashTable(array, array_length, hashTable);
	showHashTable(hashTable);
	removeKeyWord(hashTable, 65);
	showHashTable(hashTable);
	printf("isContains = [%c]\n", containsKeyword(hashTable, 23));
	destoryHashTable(&hashTable);

	return 0;
}

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