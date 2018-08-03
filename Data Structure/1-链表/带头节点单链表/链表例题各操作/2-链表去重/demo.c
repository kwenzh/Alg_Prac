#include<stdio.h>
#include<malloc.h>

#include"../../KWENLINKLISTTOOLS.h"

void deleteDumplicatesNode(LinkList *list_A);
int add(int n);

void deleteDumplicatesNowde(LinkList *list_A) {
	LinkList *p;

	if(list_A == NULL || list_A->next == NULL) {

		return;
	}

	for(p = list_A->next; p != NULL; 	p = p->next) {
		while(p->next && p->data == p->next->data) { //删除重复节点 直到下一个节点不重复 再去移动p
			LinkList *temp = p->next;
			p->next = temp->next;
			free(temp);
		}
	}


	// for(p = list_A->next; p->next != NULL; 	) {
	// 	if(p->next) {
	// 		if(p->data == p->next->data) {
	// 			LinkList *temp = p->next;
	// 			p->next = temp->next;
	// 			free(temp);
	// 		}else {
	// 			p = p->next;
	// 		}
	// 	}
	// }
}


int main(void) {
	LinkList *list_A = NULL;

	initLinkList(&list_A);
	insertDataByTail(list_A);
	showListInfor(list_A);
	deleteDumplicatesNode(list_A);
	showListInfor(list_A);

	destoryLinkList(&list_A);

	return 0;
}
