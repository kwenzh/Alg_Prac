#ifndef _KWEN_STACK_H_
#define _KWEN_STACK_H_


#include<malloc.h>

// #include"../../include/kwenbase.h"
#define true	1
#define false  0

#define MAX_SIZE	1000

typedef struct STACK_KWEN{
	int top;			//栈顶指针
	int *data;			//存储空间
	int capacity;     //表示栈中最大存储长度
}STACK_KWEN;

boolean initializeStack(STACK_KWEN **stackHead, int capacity);
boolean push(STACK_KWEN *stackHead, const int push_data);
int pop(STACK_KWEN *stackHead);
void destoryStack(STACK_KWEN **stackHead);
boolean isStackFull(STACK_KWEN *stackHead);
boolean isStackEmpty(STACK_KWEN *stackHead);
const int readTop(STACK_KWEN *stackHead);

const int readTop(STACK_KWEN *stackHead) {
	if(isStackEmpty(stackHead) || NULL == stackHead) {
		return ERROR;
	}

	return stackHead->data[stackHead->top];
}

boolean isStackEmpty(STACK_KWEN *stackHead) {
	if(NULL == stackHead) {
		return false;  //not initialize
	}

	return stackHead->top <= -1;
}

boolean isStackFull(STACK_KWEN *stackHead) {
	if(NULL == stackHead) {
		return false;  //not initialize
	}

	return stackHead->top >= stackHead->capacity;
}

boolean push(STACK_KWEN *stackHead, const int push_data) {
	if(NULL == stackHead || isStackFull(stackHead)) {
		//如果栈满 则返回 此时不能入栈
		return false;
	}

	stackHead->data[++stackHead->top] = push_data;

	return true;
}

int pop(STACK_KWEN *stackHead) {
	if(isStackEmpty(stackHead) || NULL == stackHead) {
		return ERROR;
	}

	return stackHead->data[stackHead->top--];
}

void destoryStack(STACK_KWEN **stackHead) {
	if(NULL  == stackHead || NULL == *stackHead) {
		return;
	}

	free((*stackHead)->data);
	free(*stackHead);
	*stackHead = NULL;
}

boolean initializeStack(STACK_KWEN **stackHead, int capacity) {
	if(NULL == stackHead || capacity > MAX_SIZE || capacity <= 0 || NULL != *stackHead) {
		return false;
	}

	*stackHead = (STACK_KWEN *)calloc(sizeof(STACK_KWEN), 1);
	(*stackHead)->capacity = capacity;
	(*stackHead)->top = -1;
	(*stackHead)->data = (int *)calloc(sizeof(int), capacity);
	if(NULL == (*stackHead)->data) {  //表示没有分配到空间
		free(*stackHead);
		return false;
	}

	return true;
}

#endif
