#include<stdio.h>

#include"../../KWENLINKLISTTOOLS.h"

// LinkList *addTwoNumbers(LinkList *list_A, LinkList *list_B);
/*
2
4
3
-1
5
6
4
-1
 */
LinkList *addTwoNumbers2(LinkList *list_A, LinkList *list_B) {
	LinkList *result = NULL;
	LinkList *p;
	int carry_data = 0;

	initLinkList(&result);
	p = result; 					//指向结果链表的头结点
	while(list_A || list_B || carry_data) {
		int result =  (list_A ? list_A->data: 0) + (list_B ? list_B->data : 0) + carry_data;
		carry_data  = result / 10;
		p->next = (LinkList *)calloc(sizeof(LinkList), 1);
		p = p->next;
		p->data = result % 10;
		list_A = list_A ? list_A->next : list_A;
		list_B = list_B ? list_B->next : list_B;
	}

	return result;
}

int main(void) {
	LinkList *list_A = NULL;
	LinkList *list_B = NULL;
	LinkList *result = NULL;

	initLinkList(&list_A);
	initLinkList(&list_B);

	insertDataByTail(list_A);
	insertDataByTail(list_B);

	showListInfor(list_A);
	showListInfor(list_B);

	result = addTwoNumbers2(list_A->next, list_B->next);

	showListInfor(list_A);
	showListInfor(list_B);
	showListInfor(result);

	destoryLinkList(&list_A);
	destoryLinkList(&list_B);

	return 0;
}
