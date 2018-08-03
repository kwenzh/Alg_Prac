#include<stdio.h>
#include<malloc.h>

#include"../../KWENLINKLISTTOOLS.h"

void reverseKGroup(LinkList *head, int k);

void reverseKGroup(LinkList *head, int k) {
	LinkList *p = head;
	LinkList *temp;
	int i;
	int j = 1;

	while(p) {
		temp = p;
		for(i = 0, p = p->next; p && i < k - 1 ; i++) {
			p = p->next;
		}
		printf("i = %d, p->data= %d\n", i, p->data);
		if(i == k) {
			 reverseBetween(temp, 1, k);
		}
		showListInfor(head);
	}
}

int main(void) {
	LinkList *list_A = NULL;
	LinkList *p;

	initLinkList(&list_A);
	insertDataByTail(list_A);

	showListInfor(list_A);
	reverseKGroup(list_A, 3);
	showListInfor(list_A);

	destoryLinkList(&list_A);

	return 0;
}
/*
1
2
3
4
5
6
7

 */
