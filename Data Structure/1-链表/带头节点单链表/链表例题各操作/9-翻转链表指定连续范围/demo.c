#include<stdio.h>
#include<malloc.h>

#include"../../include/kwenlinklisttools.h"

void reverseBetween(LinkList *head, int n, int m);

//1 2 3 4 5 6 7   翻转2,5， 得到1 5 4 3 2 6 7
void reverseBetween(LinkList *head, int n, int m) {
	LinkList *pre_n;
	LinkList *next_m;
	LinkList *p = head;
	LinkList *temp;
	int i;

	if(n <= 0 || m <= 0 || head->next == NULL || n >= m) {
		printf("ERROR DATA, you reverse your mother nei!")
		return;
	}

	for(pre_n = head, i = 0; i < n - 1; i++) {
		pre_n = pre_n->next;       //对于给出的链表例子，先找到2的前驱节点保存下来
	}
	for(next_m = head->next, i = 0; i < m; i++) {
		next_m = next_m->next;    //找到5的后驱节点保存下来
	}
	p = pre_n->next;    //第2个节点
	pre_n->next = NULL; //断开第n个节点与第n-1节点连接关系，也就是断开1->2的链接	
	for(i = 0; i < m - n + 1; i++) {
		temp = p->next;
		p->next = next_m;
		next_m = p;
		p = temp;
	}
	pre_n->next = next_m;   //让1指向5 ， 1->5->4->3->2->6->7
}

int main(void) {
	LinkList *list_A = NULL;

	initLinkList(&list_A);
	insertDataByTail(list_A);
	showListInfor(list_A);
	reverseBetween(list_A, 2, 5);
	showListInfor(list_A);

	destoryLinkList(&list_A);

	return 0;
}