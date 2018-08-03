#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H

#include"../../include/KWENBASE.h"

#define DELFLAG			-2
#define HashTableSize	11
#define ADDRESSTEMP		-1
#define NOT_FOUND		-1

typedef int USER_TYPE;

typedef struct Datatype {
	int key;
	USER_TYPE value;
}Datatype;

typedef struct HashTable {
	int times;
	Datatype data;
}HashTable;

//除留余数法构造哈希函数
int HashFunc(int key);
//解决冲突的线性探测再散列方法
int Collision(int di);
int HashSearch(HashTable *ht, Datatype x);
int HashInsert(HashTable *ht, Datatype x);
void CreateHashTable(HashTable *ht, Datatype *L, int L_length);
int HashTableDel(HashTable *ht, Datatype x);
void FillInData(Datatype **data, int *array, int array_length);
void destoryData(Datatype **data);
void showHashTable(HashTable *ht);
int RandomAddress(int key);
int Collision(int key);
int SecondDetection(int key);

#endif
