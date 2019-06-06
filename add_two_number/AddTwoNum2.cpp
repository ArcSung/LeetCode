class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * preHead = new ListNode(0);
        ListNode * p = preHead;
        
        int extra = 0, sum;
        while (l1 || l2 || extra)
        {
            sum = (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0) + extra;
            extra = sum / 10;
            p -> next = new ListNode(sum % 10);
            p = p -> next;
            l1 = l1 ? l1 -> next : NULL;
            l2 = l2 ? l2 -> next : NULL;
        }
        return preHead -> next;
    }
};
