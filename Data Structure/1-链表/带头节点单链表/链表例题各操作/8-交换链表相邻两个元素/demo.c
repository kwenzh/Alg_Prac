#include<stdio.h>
#include<malloc.h>

#include"../../KWENLINKLISTTOOLS.h"

//1 2 3 4   2 1 4 3
void swapPairs(LinkList *head);

void swapPairs(LinkList *head) {
	LinkList *pre;
	LinkList *p;
	LinkList *q;

	pre = head;
	while(pre->next && pre->next->next) {
		p = pre->next;
		q = pre->next->next;
		pre->next = q;
		p->next = q->next;
		q->next = p;
		pre = pre->next->next;
	}
}

int main(void) {
	LinkList *list_A = NULL;

	initLinkList(&list_A);
	insertDataByTail(list_A);
	showListInfor(list_A);
	swapPairs(list_A);
	showListInfor(list_A);

	destoryLinkList(&list_A);

	return 0;
}
