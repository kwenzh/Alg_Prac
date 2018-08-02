#ifndef _KWEN_STRING_TOOLS_H_
#define _KWEN_STRING_TOOLS_H_

#ifndef _HEAD_FILE_
#define _HEAD_FILE_
#include<malloc.h>
#include<string.h>

#include"KwenBase.h"

#endif

//字符转换为小写格式
void charToCapital(char *ch);

// 字符串全部改成小写格式
void StringToCapital(string str);

void StringtoUpper(string str);

int isLetter(const char);

//从字符串Str中下标为beginIndex的位置取出length长度字符串返回
char *substring(char *str, int beginIndex, int length);


void str_sort(char *str);
void reverse_str(char *str);
int strToInt(char *str);

int isLetter(const char ch) {
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int strToInt(char *str) {
	int i;
	int len = strlen(str);
	int sum = 0;

	for(i = 0;  i < len; i++) {
		sum = sum * 10 + (str[i] - '0');
	}

	return sum;
}

void reverse_str(char *str) {
	int i = 0;
	int j = strlen(str) - 1;

	while(i < j) {
		char temp = str[i];
		str[i] = str[j];
		str[j] = temp;

		i++;
		j--;
	}

}

void str_sort(char *str) {
	 int i;
	 int len = strlen(str);
	 int j;

	for(i = 0; i < len - 1; i++) {
		for(j = 0; j < len -1 - i; j++) {
			if(str[j] > str[j+1]) {
				char temp = str[j];
				str[j] = str[j+1];
				str[j+1] = temp;
			}
		}
	}
}

char *substring(char *str, int beginIndex, int length) {
	char *result;
	int i;

	if(beginIndex < 0 || beginIndex > strlen(str) || length < 0) {
		printf("Error beginIndex or length!");
		return "";
	}

	result = (char *)alloca(sizeof(char)*length);
	for(i = 0; i < length; i++) {
		result[i] = str[beginIndex + i];
	}

	return result;
}

void charToCapital(char *ch) {
	*ch += (*ch >= 'A' && *ch <= 'Z') ? 32 : 0;
}

void StringToCapital(string str) {
	int i;

	for(i = 0; str[i]; i++) {
		str[i] += (str[i] >= 'A' && str[i] <= 'Z') ? 32: 0;
	}            
}

#endif