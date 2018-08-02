#include<stdio.h>
#include<malloc.h>

#include"KWENLINKLISTTOOLS.h"

int main(void) {
	LinkList *list_A = NULL;


	initLinkList(&list_A);
	insertDataByTail(list_A);

	showListInfor(list_A);

	destoryLinkList(&list_A);

	return 0;
}
