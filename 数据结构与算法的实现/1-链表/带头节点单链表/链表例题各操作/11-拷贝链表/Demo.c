#include<stdio.h>
#include<malloc.h>

#include"../../include/kwenlinklisttools.h"

LinkList *copyLinkList(LinkList *pHead) {
	 LinkList *head = NULL;
     LinkList *p;
     LinkList *q = pHead->next;


     head = (LinkList *)malloc(sizeof(LinkList));
     p = head;
     while(q != NULL) {
     	LinkList *node = (LinkList *)malloc(sizeof(LinkList));
     	node->data = q->data;
     	node->next = NULL;
     	p->next = node;
     	//p = node 的报错原因？并没有将链表各个节点链接起来
     	p = p->next;
     	q = q->next;
     } 

     return head;
}

int main(void) {
	LinkList *pHead = NULL;
	LinkList *newHead = NULL;

	initLinkList(&pHead);
	insertDataByTail(pHead);
	showListInfor(pHead);

	newHead = copyLinkList(pHead);
	showListInfor(newHead);

	pHead->next->data = 10;
	showListInfor(pHead);
	showListInfor(newHead);	

	destoryLinkList(&pHead);
	destoryLinkList(&newHead);

	return 0;
}
/*
1
2
3
4
5
-1
 */