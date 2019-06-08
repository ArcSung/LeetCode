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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *cur = head;

        while(cur && cur->next) {
            stack<ListNode*> node_stack;
            for(int i = 0; i < k; i++){
                if(cur != NULL){
                    node_stack.push(cur);
                    cur = cur->next;
                }
            }
            
            if(node_stack.size() != k)
                break;
            
            while(node_stack.size()){
                prev->next = node_stack.top();
                node_stack.pop();
                prev = prev->next;
            }
            
            prev->next = cur;
        }

        return dummy->next;
    }
};
