#ifndef _KWEN_LINKLIST_TOOLS_H_
#define _KWEN_LINKLIST_TOOLS_H_

#include<malloc.h>

#include"KWENBASE.h"

typedef int DataType;

typedef struct LinkList {
	DataType data;
	struct LinkList *next;
}LinkList;

//链表的初始化 得到一条只有头结点的链表
void initLinkList(LinkList **head);

//销毁释放掉链表中每个节点空间
void destoryLinkList(LinkList **head);

//打印存放数据 带头结点链表 跳过第一个head头结点
void showListInfor(LinkList *head);

//头插法添加数据
void insertDataByHead(LinkList *head);

//尾插法建立链表 每次保留新的尾节点也就是head->next == NULL的head结点
void insertDataByTail(LinkList *head);

// 返回链表中第index个节点
LinkList *indexOf(LinkList *head, int index);

// 输入一个节点的数据，如果链表存在此数据 返回第一次出现的节点
LinkList *searchNodeByData(LinkList *head, DataType data);

// 在链表中第index节点后插入数据data
// 根绝index得到的节点判断是否存在 ，若为NULL，说明index不在链表长度内 插入失败
// 反之则进行插入数据操作 插入成功
boolean insertElement(LinkList *head, int index, DataType data);

// 要删除链表第i个节点，先找到第i-1个节点是否存在
int deleteElementByIndex(LinkList *head, int deleteIndex);

// 链表的反转，有两种思路
// 改变每个节点之间的指向关系
// 断开头结点和第一个节点 ，最后一次让头结点指向最后一个节点
// 关于对链表的翻转函数是否需要返回值还需要进一步的讨论，是返回一个新的链表还是
// 在原链表的空间上进行操作，改变原链表的排列顺序
void reverseList_1(LinkList *head);

// 1、把头结点后面的数据，逐个插入到当前头结点的后面
void reverseList_2(LinkList *head);

//翻转一个链表中指定第n个节点到第m个节点，例如链表9->8->5->6->2->4->1->null, n = 2, m = 5
//得到9->2->6->5->8->4->1->null
void reverseBetween(LinkList *head, int n, int m);

//这样合并两个链表之后会造成环链的情况
//因为新合并的链表并没有申请新的空间，也是指向传递进来两个链表的空间，所以就造成了环链的情况
//这里应该对此函数进行改进。新合成的链表需要新申请空间，赋值则是通过两个链表数据大小比较赋值
LinkList *mergeList(LinkList *list_A, LinkList *list_B);

//把一个链表看成一个表示数据例如8->9->7,可表示798，完成两个链表的相加功能
LinkList *addTwoNumbers(LinkList *list_A, LinkList *list_B);

int getLinkListLength(LinkList *head);



LinkList *copyLinkList(LinkList *pHead) {
	 LinkList *head = NULL;
     LinkList *p;
     LinkList *q = pHead->next;


     head = (LinkList *)malloc(sizeof(LinkList));
     p = head;
     while(q != NULL) {
     	LinkList *node = (LinkList *)malloc(sizeof(LinkList));
     	node->data = q->data;
     	node->next = NULL;
     	p->next = node;
     	//p = node 的报错原因？并没有将链表各个节点链接起来
     	p = p->next;
     	q = q->next;
     }

     return head;
}


//1 2 3 4 5 6 7   翻转2,5， 得到1 5 4 3 2 6 7
void reverseBetween(LinkList *head, int n, int m) {
	LinkList *pre_n;
	LinkList *next_m;
	LinkList *p = head;
	LinkList *temp;
	int i;

	for(pre_n = head, i = 0; i < n - 1; i++) {
		pre_n = pre_n->next;       //对于给出的链表例子，先找到2的前驱节点保存下来
	}
	for(next_m = head->next, i = 0; i < m; i++) {
		next_m = next_m->next;    //找到5的后驱节点保存下来
	}

	p = pre_n->next;    //第2个节点
	pre_n->next = NULL; //断开第n个节点与第n-1节点连接关系，也就是断开1->2的链接
//这里的翻转和翻转整个链表思路完全相同可参考reverseList_1函数，改变相邻两个节点之间的指向关系
	for(i = 0; i < m - n + 1; i++) {
//保存当前要更改指向关系节点的后驱节点
		temp = p->next;
//改变指向关系
		p->next = next_m;
//更新翻转部分的头
		next_m = p;
//更新节点p的值
		p = temp;
	}
//循环前断开的部分链接上
	pre_n->next = next_m;   //让1指向5 ， 1->5->4->3->2->6->7
}

int getLinkListLength(LinkList *head) {
	int count = 0;

	while(head->next) {
		head = head->next;
		count++;
	}

	return count;
}

LinkList *addTwoNumbers(LinkList *list_A, LinkList *list_B) {
	LinkList *result = NULL;
	LinkList *p;
	int carry_data = 0;

	initLinkList(&result);
	p = result; 					//指向结果链表的头结点
	while(list_A || list_B || carry_data) {
		int result =  (list_A ? list_A->data: 0) + (list_B ? list_B->data : 0) + carry_data;
		carry_data  = result / 10;
		p->next = (LinkList *)calloc(sizeof(LinkList), 1);
		p = p->next;
		p->data = result % 10;
		list_A = list_A ? list_A->next : list_A;
		list_B = list_B ? list_B->next : list_B;
	}

	return result;
}

LinkList *mergeList(LinkList *list_A, LinkList *list_B) {
	LinkList *result_list;
	LinkList *head;

	initLinkList(&result_list);
	head = result_list;
	list_A = list_A->next;
	list_B = list_B->next;
	for(; list_A && list_B; result_list = result_list->next) {
		if(list_A->data < list_B->data) {
			result_list->next = list_A;
			list_A = list_A->next;
		}else {
			result_list->next = list_B;
			list_B = list_B->next;
		}
	}
	if(list_A) {
		result_list->next = list_A;
	}if(list_B) {
		result_list->next = list_B;
	}

	return head;
}

void reverseList_2(LinkList *head) {
	LinkList *p;
	LinkList *tmp;

	p = head->next;
	head->next = NULL;
	while(p) {
		tmp  = p;
		p = p->next;
		tmp->next = head->next;
		head->next = tmp;
	}
}

void reverseList_1(LinkList *head) {
	LinkList *p;
	LinkList *q;
	LinkList *tmp;

	p = head->next;				//保留链表第一个节点
	head->next = NULL;
	q = NULL;
	while(NULL !=  p) {
		tmp = p->next;
		p->next = q;
		q = p;
		p = tmp;
	}

	head->next = q;
}

int deleteElementByIndex(LinkList *head, int deleteIndex) {
	LinkList *p;
	LinkList *tmp;

	p = indexOf(head, deleteIndex);

	if(NULL == p) {
		printf("ERROR delete Index !");
		return false;
	}

//找到要删除节点p的前驱节点 如果要删除第一个节点 说明它的前驱节点就是头结点
	tmp = deleteIndex == 1 ? head : indexOf(head, deleteIndex - 1);
	tmp->next = p->next;
	free(p);

	return true;
}

LinkList *indexOf(LinkList *head, int index) {
	LinkList *p;
	int j;

	for(j = 1, p = head->next; NULL != p && j < index; j++, p = p->next);

	return j == index ? p : NULL;
}


boolean insertElement(LinkList *head, int index, DataType data) {
	LinkList *p;
	LinkList *newNode;

	p = indexOf(head, index);

	if(NULL == p) {
		printf("Error insert index !\n");
		return false;
	}

	newNode = (LinkList *)malloc(sizeof(LinkList));
	newNode->data = data;
	newNode->next = p->next;
	p->next = newNode;

	return true;
}


LinkList *searchNodeByData(LinkList *head, DataType data) {
	LinkList *p;

	for(p = head; NULL != p && p->data != data; p = p->next);

	return p;
}



void showListInfor(LinkList *head) {
	head = head->next;

	while(NULL != head) {
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}

void insertDataByTail(LinkList *head) {
	int x;
	LinkList *node;
	LinkList *remove;

	while(NULL != head->next) {
//如果链表里面已经有数据了需要找到链表中最后一个节点
		head = head->next;
	}
	remove = head;

	printf("input the data (-1 stop): ");
	scanf("%d", &x);
	while(x != -1) {
		node = (LinkList *)malloc(sizeof(LinkList));
		node->data = x;
		node->next = remove->next;
		remove->next = node;
		remove = node;
		printf("input the data (-1 stop): ");
		scanf("%d", &x);
	}

}

void insertDataByHead(LinkList *head) {
	int x;
	LinkList *node;

	printf("input the data (-1 stop): ");
	scanf("%d", &x);
	while(x != -1) {
		node = (LinkList *)malloc(sizeof(LinkList));
		node->data = x;
		node->next = head->next;
		head->next = node;
		printf("input the data (-1 stop): ");
		scanf("%d", &x);
	}
}

// void destoryLinkList(LinkList **head) {
// 	LinkList *header = *head;
// 	LinkList *p = NULL;

// 	while(NULL != header) {
// 		p = header;			//保存当前结点
// 		header = p->next;   //让当前头结点指向下一个节点
// 		free(p);			//把保存的节点释放掉
// 	}
// 	free(header);
// 	head = NULL;
// }

//递归的销毁方式
void destoryLinkList(LinkList **head) {
	if(NULL == *head) {
		return;
	}

	destoryLinkList(&((*head)->next));
	free(*head);
	*head = NULL;
}

void initLinkList(LinkList **head) {
	if((*head) != NULL) {
//表示该链表已经被初始化过了不需要生成头结点
		return;
	}

	*head = (LinkList *)malloc(sizeof(LinkList));
	(*head)->data = 0;
	(*head)->next = NULL;
}

#endif
