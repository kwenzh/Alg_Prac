/*
题目描述
输入一个链表，反转链表后，输出新链表的表头。

*/

// 反转链表有很多做法 有重新头插法建立一遍

// 这里的思路是: 直接改变每两个链表之间的指向关系
ListNode* ReverseList(ListNode* pHead) {
    ListNode *p;
    ListNode *q;
    ListNode *tmp;

    if(pHead == NULL || pHead->next == NULL) {
        return pHead;
    }

    p = pHead;				//保留链表第一个节点
    q = NULL;
    while(NULL !=  p) {
        tmp = p->next;
        p->next = q;
        q = p;
        p = tmp;
    }

    return q;
}
