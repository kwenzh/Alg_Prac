#include<stdio.h>
#include<malloc.h>

#include"HashTable.h"

int main(void) {
	DataType array[] = {2,3,4,65,23,54,12,24,25};
	int array_length = sizeof(array) / sizeof(DataType);
	HASHTABLE *hashTable = NULL;

	hashTable = (HASHTABLE *)calloc(sizeof(HASHTABLE), HASHTABLESIZE);
	createHashTable(array, array_length, hashTable);
	showHashTable(hashTable);
	removeKeyWord(hashTable, 65);
	showHashTable(hashTable);

	destoryHashTable(&hashTable);

	return 0;
}

// #include<stdio.h>
//
// typedef  char DataType;
//
// void show(void *p);
//
// void show(void *p) {
// 	DataType *x;
//
// 	x = (DataType *)p;
//
// 	printf("%c\n", *x);
// }
//
// int main(void){
// 	DataType num = 4;
// 	void *p = &num;
// 	DataType *p2 = (DataType *)p;
//
// 	show(p);
//
// 	printf("%c\n", *p2);
//
// 	return 0;
// }
