#include<stdio.h>
#include<malloc.h>

#include"../../KWENLINKLISTTOOLS.h"

void deleteAllNodeByValue(LinkList *list_A, int value);

void deleteAllNodeByValue(LinkList *list_A, int value) {
	LinkList *p;
	LinkList *temp;

	for(p = list_A; p->next; ) {
		if(p->next->data == value) {
			temp = p->next;
			p->next = p->next->next;
			free(temp);
		}else {
			p = p->next;
		}
	}
}


int main(void) {
	LinkList *list_A = NULL;

	initLinkList(&list_A);
	insertDataByTail(list_A);
	showListInfor(list_A);

	deleteAllNodeByValue(list_A, 3);

	showListInfor(list_A);

	destoryLinkList(&list_A);

	return 0;
}
