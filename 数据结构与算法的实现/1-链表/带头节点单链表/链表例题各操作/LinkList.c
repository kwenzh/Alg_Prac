#include<stdio.h>

#include"../include/KwenLinkListTools.h"

LinkList partition(LinkList *head, int value);

LinkList partition(LinkList *head, int value) {
	LinkList node1 = {0};
	LinkList node2 = {0};
	LinkList *p1 = &node1;
	LinkList *p2 = &node2;

	head = head->next;
	while(head) {
		if(head->data < value) {
			p1 = p1->next = head;
		} else {
			p2 = p2->next = head;
		}
		head = head->next;
	}
	p2->next = NULL;
	p1->next = node2.next;

	return node1;
}


int main(void) {
	LinkList *list_A = NULL;
	int x;
	LinkList result = {0};

	initLinkList(&list_A);
	insertDataByTail(list_A);
	showListInfor(list_A);

	result = partition(list_A, 3);

	showListInfor(&result);
	showListInfor(list_A);

	destoryLinkList(&list_A);


	return 0;
}