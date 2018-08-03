#include<stdio.h>
#include<malloc.h>

#include"../../KWENLINKLISTTOOLS.h"

void RemoveNthNodeFromEndofList(LinkList *head, int n);

void RemoveNthNodeFromEndofList_2(LinkList *head, int n);

//Linus Torvalds 的双重指针方法
//先让一个指针fast走n步，在第二循环中让另外一个指针slow从头走，走了n步指针fast接着走直到链表尾
//这时slow走到的地方就是要删除节点的前驱节点 真是太牛逼了
void RemoveNthNodeFromEndofList_2(LinkList *head, int n) {
	LinkList *fast = head;
	LinkList *slow = head;
	LinkList *temp;

	if(head == NULL || n == 0) {
		return;
	}
	while(n-- > 0) {
		if(fast == NULL) {
			return;
		}
		fast = fast->next;
	}

	while(fast->next) {
		fast = fast->next;
		slow = slow->next;
	}

	temp = slow->next;
	slow->next = temp->next;
	free(temp);
}

//笨办法删除 先得到链表长度
void RemoveNthNodeFromEndofList(LinkList *head, int n) {
	int length = getLinkListLength(head);
	int index = length - n + 1;
	int i;
	LinkList *temp;

	for(i = 0; i < index - 1; i++) {
		head = head->next;
	}
	temp = head->next;
	head->next = temp->next;
	free(temp);
}

int main(void) {
	LinkList *list_A = NULL;


	initLinkList(&list_A);
	insertDataByTail(list_A);
	showListInfor(list_A);
	RemoveNthNodeFromEndofList_2(list_A, 2);
	showListInfor(list_A);

	destoryLinkList(&list_A);

	return 0;
}
