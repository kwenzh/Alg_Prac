#include<stdio.h>
#include<malloc.h>

#include"../../include/KWENBASE.h"

typedef int DataType;

typedef struct TwLinkList{
	DataType data;
	struct TwLinkList *next;
	struct TwLinkList *pre;
}TwLinkList;

void initTwLinkList(TwLinkList **);
void destoryLinkList(TwLinkList **);
void showListInfor(TwLinkList *);
void showDataType(DataType);
void createLinkListByTail(TwLinkList *);
// 在链表中第index节点后插入数据data
// 根绝index得到的节点判断是否存在 ，若为NULL，说明index不在链表长度内 插入失败
// 反之则进行插入数据操作 插入成功
boolean insertElement(TwLinkList *head, int index, DataType data);

boolean deleteElementByIndex(TwLinkList *head, int deleteIndex);

TwLinkList *indexOf(TwLinkList *head, int index);



boolean deleteElementByIndex(TwLinkList *head, int deleteIndex) {
	TwLinkList *p;
	TwLinkList *tmp;

	p = indexOf(head, deleteIndex);

	if(NULL == p) {
		printf("ERROR delete Index !");
		return false;
	}

	if(p->next) {
		p->next->pre = p->pre;
		p->pre->next = p->next;
	}else {
		TwLinkList *temp = p->pre;
		temp->next = NULL;
		// p->pre->next == NULL; //这么写会错的原因 根本没有改变前驱节点的指向
	}

	free(p);
	p = NULL;

	return true;
}

TwLinkList *indexOf(TwLinkList *head, int index) {
	TwLinkList *p;
	int j;

	for(j = 1, p = head->next; NULL != p && j < index; j++, p = p->next);

	return j == index ? p : NULL;
}

boolean insertElement(TwLinkList *head, int index, DataType data) {
	TwLinkList *p = NULL;
	TwLinkList *newNode;

	p = indexOf(head, index);

	if(NULL == p) {
		printf("Error insert index !\n");
		return false;
	}

	newNode = (TwLinkList *)calloc(sizeof(TwLinkList), 1);
	newNode->data = data;

	p->next && (p->next->pre = newNode);
	newNode->next = p->next;
	newNode->pre = p;
	p->next = newNode;

	return true;
}

void createLinkListByTail(TwLinkList *head) {
	TwLinkList *pMove = NULL;
	TwLinkList *node;
	DataType val;


	while(NULL != head->next) {
		head = head->next;
	}
	pMove = head;

	printf("input the data (-1 stop): ");
	scanf("%d", &val);
	while(val != -1) {
		node = (TwLinkList *)calloc(sizeof(TwLinkList), 1);
		node->data = val;
		node->next = pMove->next;
		node->pre = pMove;
		pMove->next = node;
		pMove = node;
		printf("input the data (-1 stop): ");
		scanf("%d", &val);
	}
}

void showDataType(DataType data) {
	printf("%d ", data);
}

void showListInfor(TwLinkList *list) {
	TwLinkList *p;

	p =  list->next;

	while(p != NULL) {
		showDataType(p->data);
		p = p->next;
	}

	puts("\n");
}

void destoryLinkList2(TwLinkList **head) {
	if((*head) == NULL) {
		return;
	}

	destoryLinkList(&((*head)->next));
	free(*head);
	*head = NULL;
}

void destoryLinkList(TwLinkList **head) {
	TwLinkList *header = *head;
	TwLinkList *p;

	if((*head) == NULL) {
		return;
	}
	while(NULL != header) {
		p = header;
		header = p->next;
		free(p);
	}

	free(header);
	head = NULL;
}

void initTwLinkList(TwLinkList **head){
	if((*head) != NULL) {
		return ;
	}

	(*head) = (TwLinkList *)malloc(sizeof(TwLinkList));
	(*head)->next = NULL;
	(*head)->pre = NULL;
}

int main(void){
	TwLinkList *list = NULL;

	initTwLinkList(&list);
	createLinkListByTail(list);
	showListInfor(list);

	// insertElement(list, 2, 15);
	// showListInfor(list);

	deleteElementByIndex(list, 3);
	showListInfor(list);

	destoryLinkList(&list);


	return 0;
}
