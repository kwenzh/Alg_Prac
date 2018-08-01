/*
题目描述
输入两个单调递增的链表，输出两个链表合成后的链表，当然我们需要合成后的链表满足单调不减规则。

*/

//判断大小然后确定新表头的指向
// 注意当其中一个为空的情况
ListNode* Merge(ListNode* pHead1, ListNode* pHead2){
  ListNode *result_list;
	ListNode *head;

	result_list = (ListNode *)malloc(sizeof(ListNode));
	head = result_list;

  if(pHead1 == NULL) {
		return pHead2;
	}
	if(pHead2 == NULL) {
		return pHead1;
	}
	if(pHead1 == NULL && pHead2 == NULL) {
		return NULL;
	}

	for(; pHead1 && pHead2; result_list = result_list->next) {
		if(pHead1->val < pHead2->val) {
			result_list->next = pHead1;
			pHead1 = pHead1->next;
		}else {
			result_list->next = pHead2;
			pHead2 = pHead2->next;
		}
	}

  // 如果其中一个还有剩余 接着指向
	if(pHead1) {
		result_list->next = pHead1;
	}if(pHead2) {
		result_list->next = pHead2;
	}

	return head->next;
}
