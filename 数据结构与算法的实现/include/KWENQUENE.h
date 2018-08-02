#ifndef _KWEN_QUENE_H_
#define _KWEN_QUENE_H_

#include<malloc.h>

#include"../../include/kwenbase.h"

typedef int DataQueneType;

typedef struct QUENE {
	DataQueneType *data;
	int maxRoom;
	int rear;   //只允许在后端进行插入操作
	int front;   //只允许在前端进行删除操作
	boolean flag;  
}QUENE;

//对一个新的队列初始化，头尾指针均为0，根据传递进来的maxRoom申请队列数据空间
void initializeQuene(QUENE **queneHead, int maxRoom);

//入队操作，若队未满，可以入队，入队在尾指针rear处操作，rear指针去追赶头指针front
boolean EnQuene(QUENE *queneHead, DataQueneType data);

//出队操作，若队未空，可以出队，出队在头指针front操作，front指针去追赶指针rear
void DeQuene(QUENE *queneHead, DataQueneType *data);

// 销毁一个队列
void destoryQuene(QUENE **queneHead);

//判断队空队满不能像判断栈一样去判断top指针，队列是一个环形结构
//存在front == rear时候，队满队空都有可能存在
//说明两种方法：
//1、结构体增加一个记录队列实际元素的count，入队成功一个count++，出队成功一个count--
//2、结构体添加一个bool类型标记，
// 判断队是否为空，队空有两个前提，头尾指针相遇，并且当前flag是false，也就是上一次做的是出队操作
// 出队的时候flag= 0，出队的时候是头指针front去追赶尾指针rear，当front==rear && flag = 0，说明此时队空
boolean isQueneEmpty(QUENE *queneHead);

//入队的时候flag= 1,入队的时候是尾指针rear去追赶头指针front，当rear==front && flag == 1说明 此时队满
//此时的flag为true并且头尾指针相遇,说明上一次做的是入队操作,此时已经队满了
boolean isQueneFull(QUENE *queneHead);

boolean isQueneFull(QUENE *queneHead) {
	return true == queneHead->flag && queneHead->rear == queneHead->front;
}

boolean isQueneEmpty(QUENE *queneHead) {
	return false == queneHead->flag && queneHead->rear == queneHead->front;
}

void DeQuene(QUENE *queneHead, DataQueneType *data) {
	if(isQueneEmpty(queneHead)) {
		printf("Quene is empty!\n");
		return;
	}

	*data = queneHead->data[queneHead->front];
	queneHead->front = (queneHead->front + 1) % queneHead->maxRoom;
	queneHead->flag = false;
}

boolean EnQuene(QUENE *queneHead, DataQueneType data) {
	if(isQueneFull(queneHead)) {
		printf("Quene is Full! no EnQuene!\n");
		return false;
	}

	queneHead->data[queneHead->rear] = data;
	queneHead->rear = (queneHead->rear + 1) % queneHead->maxRoom;
	queneHead->flag = true;

	return true;
}

void destoryQuene(QUENE **queneHead) {
	if(NULL == *queneHead || NULL == queneHead) {
		return;
	}

	free((*queneHead)->data);
	free(*queneHead);
	*queneHead = NULL;
}

void initializeQuene(QUENE **queneHead, int maxRoom) {
	if(NULL != *queneHead || maxRoom <= 0) {
		return;
	}

	(*queneHead) = (QUENE *)calloc(sizeof(QUENE), 1);
	if(NULL == *queneHead) {	
		return;
	}

	(*queneHead)->data = (DataQueneType *)calloc(sizeof(int), maxRoom);
	if((*queneHead)->data == NULL) {
		// 没有分配到空间
		free(*queneHead);
		return;
	}
	
	(*queneHead)->maxRoom = maxRoom;
	(*queneHead)->rear = (*queneHead)->front = 0;  //这里初始化给成-1要更合适点
	(*queneHead)->flag = false;
}


#endif