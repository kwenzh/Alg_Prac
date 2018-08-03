#include<stdio.h>
#include<malloc.h>

#include"../../KWENLINKLISTTOOLS.h"

void deleteNode(LinkList *list_A);
void deleteNode(LinkList *list_A) {
	if(list_A->next) {
		list_A->data = list_A->next->data;
		list_A->next= list_A->next->next;
	}else {
		list_A = NULL;
	}
}

int main(void) {
	LinkList *list_A = NULL;
	LinkList *p;
	int i;
	int n = 3;

	initLinkList(&list_A);
	insertDataByTail(list_A);
	showListInfor(list_A);
	p = list_A;
for(i = 0; i < n; i++) {
	p = p->next;
}
	deleteNode(p);

	showListInfor(list_A);

	destoryLinkList(&list_A);

	return 0;
}
