/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        
        
        while(cur){
            if(pre != NULL && pre->val == cur->val)
                pre->next = cur->next;
            else
                pre = cur;
        
            cur = cur->next;
        }
        
        return head;
    }
};
