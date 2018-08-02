/*
题目描述
给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。

*/

//链表中是否有环 就用快慢指针判断 而找出这个环的入口 当两指针相遇的时候
// 让一个指针从头重新走 另一个指针就从相遇的地方走 下一次他们相遇的地方就是入口

// 这个可以证明的 我们分别设链表头距环入口a步, 环的长度也就是周长b步 单位步是一个next
// fast速度:2 slow速度1  相遇时间位X 那么快慢指针走过的步数为:2X和X

// 可得关系式:(2X-a)%b = (X-a)%b
// 然后证明:a = b - (X-a)%b + k*b      ,  k = 0,1,2,....
// (2X-a)%b = (X-a)%b这个可以推出来 x = kb && x >= a
/*
不妨设: (2X-a)%b = (X-a)%b = n
 X - a = m1*b + n     m1 = (X-a)/b
 2X - a = m2*b + n    m2 = (2X-a)/b

 可得X = (m2 - m1) * b
 代入可得:a = b*(m2 - 2*m1) - n = b*(m2 - 2*m1) - (X-a)%b
 化简证明的式子: a = b - (X-a)%b + k*b = (k + 1)b - (X-a)%b
 a = b* (k + 1) - (X-a)%b
 a = b*(m2 - 2*m1) - (X-a)%b
 k = 0,1,2,....
 (k+1)和(m2 - 2*m1)一定相同 得证
*/
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
  if(pHead->next == NULL || pHead->next->next == NULL) {
    return NULL;
  }
  ListNode *fast = pHead;
  ListNode *slow = pHead;

  for(fast = fast->next->next, slow = slow->next; slow != fast; ) {
    fast = fast->next->next;
    slow = slow->next;
  }
  fast = pHead;
  while(fast != slow) {
    slow = slow->next;
    fast = fast->next;
  }

  return slow;
}
