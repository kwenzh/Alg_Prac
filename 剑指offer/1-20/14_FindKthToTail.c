
/*
题目描述
输入一个链表，输出该链表中倒数第k个结点。
*/

// 经典的问题
// 笨办法:得到链表长度 然后再得到倒数

// 快慢指针 第一个指针走k步 接着让第二个指针从头走 接着两一块走
 // 直到第一个指针到链表尾部 第二个指针就是所求节点
 // 这种思想很值得学习
ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
  ListNode *fast = pListHead;
  ListNode *slow = pListHead;

  if(pListHead == NULL || k == 0) {
    return NULL;
  }
  while(k-- > 0) {
    if(fast == NULL) {
      return NULL;
    }
    fast = fast->next;
  }

  while(fast) {
    fast = fast->next;
    slow = slow->next;
  }

  return slow;
}
