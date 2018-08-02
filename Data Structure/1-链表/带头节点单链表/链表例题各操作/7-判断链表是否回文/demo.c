#include<stdio.h>
#include<malloc.h>

#include"../../include/kwenlinklisttools.h"

boolean isPalindromeLinkList(LinkList *head);

boolean isPalindromeLinkList(LinkList *head) {
	LinkList *fast = head->next;
	LinkList *slow = head->next;

	while(fast->next != NULL && fast->next->next != NULL) {
		slow = slow->next;
		fast = fast->next->next;
	}
	reverseList_1(slow);			//把slow当做头结点翻转后面的链表数据
	for(fast = head->next, slow = slow->next; slow != NULL) {
		if(slow->data != fast->data) {
			return false;
		}
		slow = slow->next;
		fast = fast->next;
	}

	return true;
}

int main(void) {
	LinkList *list_A = NULL;

	initLinkList(&list_A);
	insertDataByTail(list_A);
	showListInfor(list_A);
	printf("%d\n", isPalindromeLinkList(list_A));
	showListInfor(list_A);

	destoryLinkList(&list_A);

	return 0;
}