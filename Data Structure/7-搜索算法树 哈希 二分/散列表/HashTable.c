#include<stdio.h>

#include"HashTable.h"
#include"../../include/KWENARRAYTOOLS.h"


int Collision(int key) {
	return (key + 1) % HashTableSize;
}

int RandomAddress(int key) {
//产生1-HashTableSize 的随机数
	srand(time(NULL));

	return key = (key + ((rand() % HashTableSize) + 1) ) % HashTableSize;
}

void showHashTable(HashTable *ht) {
	int i;

	for(i = 0; i < HashTableSize; i++) {
		printf("[%d,%d] ", i, ht[i].data.key);
	}

	printf("\n");
}

void destoryData(Datatype **data) {
	free(*data);
	*data = NULL;
}

void FillInData(Datatype **data, int *array, int array_length) {
	int i;

	*data = (Datatype *)calloc(sizeof(Datatype), array_length);
	for(i = 0; i < array_length; i++) {
//提供的数列装入Datatype
		(*data)[i].key = array[i];
	}
}

int HashTableDel(HashTable *ht, Datatype x) {
	int address;

//删除的时候还是要根据传递进来x找到对应的hash键值
//通过第一次取余计算哈希地址有可能不是真正的哈希地址，发生碰撞的情况
//就需要解决哈希碰撞问题
//先找到要删除x的对应哈希地址
	address = HashSearch(ht, x);
	if(address != NOT_FOUND) {
		ht[address].data.key = ADDRESSTEMP;
		return true;
	}else {
		return false;	//说明要删除的x不存在哈希表中
	}
}

int HashSearch(HashTable *ht, Datatype x) {
	int address;

	address = HashFunc(x.key);
	while(ht[address].data.key != ADDRESSTEMP && ht[address].data.key != x.key) {
		address = Collision(address);  //解决冲突
	}
	if(ht[address].data.key == x.key) {
		return address;
	}else {
		return NOT_FOUND;
	}
}


void CreateHashTable(HashTable *ht, Datatype *L, int L_length) {
	int i;

	for(i = 0; i < HashTableSize; i++) {
		ht[i].data.key = ADDRESSTEMP;
		ht[i].times = 0;
	}

	for(i = 0; i < L_length; i++) {
		HashInsert(ht, L[i]);
	}
}

int HashInsert(HashTable *ht, Datatype x) {
	int address;
//这里的插入算法首先得找到一个空的散列地址 如果找到地址已经存在一个元素
//说明产生了哈希碰撞，需要解决碰撞，

	address = HashFunc(x.key);
	if(address >= 0) {
		if(x.key == ht[address].data.key) {
			printf("%d is existed \n", x.key);
			return false;
		}else {
//说明发生了哈希碰撞当前这个位置就不行
//需要找到一个空地址
//给老子找！
			while(ht[address].data.key != ADDRESSTEMP) {
				address = Collision(address);
			}
		}
	}

	ht[address].data = x;     //计算的ht[address]赋值存放
	ht[address].times = 1;

	return true;
}



int HashFunc(int key) {
//除留取余的构造哈希函数方法
	return key % HashTableSize;
}

int main(void) {
	HashTable ht[HashTableSize];
	int array[] = {19,21,23,14,55,68,11,82,36};
	int array_length = sizeof(array) / sizeof(int);
	int i;
	Datatype *L;
	int result_address;

	printf("%d\n", (-2) % 10);

	showArray(array, array_length);
	FillInData(&L, array, array_length);
	CreateHashTable(ht, L, array_length);
	showHashTable(ht);
	for(i = 0; i < array_length; i++) {
		result_address = HashSearch(ht, L[i]);
		printf("[%d]result_address = %d\n", L[i].key, result_address);
	}
	HashTableDel(ht, L[1]);
	showHashTable(ht);
	for(i = 0; i < array_length; i++) {
		result_address = HashSearch(ht, L[i]);
		printf("[%d]result_address = %d\n", L[i].key, result_address);
	}


	destoryData(&L);

	return 0;
}
