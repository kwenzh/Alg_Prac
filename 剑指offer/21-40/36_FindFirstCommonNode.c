/*
题目描述
输入两个链表，找出它们的第一个公共结点。

*/

//如果两个链表有公共节点 他两的尾节点一定相同
ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
  ListNode *p;

  while(pHead1) {
    p = pHead2;
    while(p) {
    if(pHead1 == p) {
    	return p;
    }
    p = p->next;
  }

  pHead1 = pHead1->next;
  }

  return NULL;
}
