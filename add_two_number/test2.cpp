ListNode *AddTwoNum(ListNode *L1, ListNode *L2){
	ListNode * preHead = new ListNode(0);
	ListNode * p = preHead;
	int extra = 0, sum;

	while(L1 != NULL || L2 != NULL || extra != 0){
		sum = (L1 != NULL ? L1->val : 0) + (L2 != NULL ? L2->val : 0) + extra;
		extra = sum / 10;
		p->next = new ListNode(sum % 10);

		p = p -> next;
		L1 = L1 ? L1->next : NULL;
		L2 = L2 ? L2->next : NULL;
	}
	return preHead->next;
}
