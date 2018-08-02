#include<stdio.h>
#include<string.h>
#include<malloc.h>

#include"../../include/kwenarrayTools.h"

#define NOT_FOUND  -1

//KMP串匹配算法
int StrMatchKMP(char *libraryStr, char *subStr);

//得到一个数组根据目标串 在匹配的时候每次失配时 下次从哪个位置继续匹配
void getNextLocal(char *subStr, int *array);


void getNextLocal(char *subStr, int *array) {
	int index = 2;
	int value = 0;

	if(strlen(subStr) <= 2) {
		return;
	}

	while(subStr[index]) {
		if(subStr[index - 1] == subStr[value]) {
			array[index++] = ++value;
		}else if(value == 0) {
			array[index++] = 0;
		}else {
			value = array[value];
		}
	}
}

int StrMatchKMP(char *libraryStr, char *subStr) {
	int *nextLocalArray;
	int libraryStr_len = strlen(libraryStr);
	int subStr_len = strlen(subStr);
	int libraryStr_index = 0;
	int subStr_index = 0;

	nextLocalArray = (int *)calloc(sizeof(int), subStr_len);
	getNextLocal(subStr, nextLocalArray);
	showArray_1(nextLocalArray, subStr_len);
	while(libraryStr_len - subStr_len + subStr_index - libraryStr_index >= 0) {
		if(0 == subStr[subStr_index]) {
			free(nextLocalArray);

			return libraryStr_index - subStr_index;
		}else if(libraryStr[libraryStr_index] == subStr[subStr_index]) {
			subStr_index++;
			libraryStr_index++;
		}else if(subStr_index == 0) {
			libraryStr_index++;
		}else {
			subStr_index = nextLocalArray[subStr_index];
		}
	}

	free(nextLocalArray);

	return NOT_FOUND;
}

int main(void) {
	char *libraryStr = "BABCBABCABCAABCABCACABC";
	char *subStr = "ABCABCACAB";
	
	int matchedIndex = StrMatchKMP(libraryStr, subStr);
	
	printf("matchedIndex = %d\n", matchedIndex);

	puts(libraryStr);
	while(matchedIndex-- > 0) {
		putchar(' ');
	}
	puts(subStr);


	return 0;
}
