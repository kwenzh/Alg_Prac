/*
题目描述
在一个排序的链表中，存在重复的结点，请删除该链表中重复的结点，
重复的结点不保留，返回链表头指针。 例如，链表1->2->3->3->4->4->5 处理后为 1->2->5
*/

//遇到重复的时候 一直删除 直到删完
ListNode* deleteDuplication(ListNode* pHead)
{
  ListNode **curNext = &pHead;
  ListNode *cur = pHead;

  if(pHead == NULL || pHead->next == NULL) {
    return pHead;
  }

  while(cur != NULL) {
    ListNode *temp = cur;
    while(NULL != cur->next && cur->next->val == cur->val) {
      cur = cur->next;
    }
    if(cur == temp) {
      *curNext = temp;
      curNext = &((*curNext)->next);
    }
    cur = cur->next;
  }
  *curNext = NULL;

  return pHead;
}
