#include<stdio.h>
#include<malloc.h>


//前提是链表是非递减的
#include"../../KWENLINKLISTTOOLS.h"

void deleteAllDuplicateEle(LinkList *head);

void deleteAllDuplicateEle(LinkList *head) {
	LinkList *p = head;
	LinkList *temp;
	LinkList *q = p->next;

	while(p->next && q->next && q) {
		if(q->data == q->next->data) {
			int value = q->data;
			while(q && value == q->data) {
				temp = q;
				q = p->next = q->next;
				free(temp);
			}
		}else {
			p = p->next;
			q = p->next;
		}
	}
}

int main(void) {
	LinkList *list_A = NULL;

	initLinkList(&list_A);
	insertDataByTail(list_A);
	showListInfor(list_A);
	deleteAllDuplicateEle(list_A);
	showListInfor(list_A);

	destoryLinkList(&list_A);

	return 0;
}
