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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
            return head;
        
        ListNode *d = new ListNode(-1);
        stack<ListNode*> s;
        d->next = head;
        
        ListNode* pre = d, *cur = d->next;
        int i = 1;
        
        while(i < m){
            pre = cur;
            cur = cur->next;
            i++;
        }
        
        while(i <= n){
            s.push(cur);
            cur = cur->next;
            i++;
        }
        
        
        while(!s.empty()){
            pre->next = s.top(); s.pop();
            pre = pre->next;
        }
        
        ListNode *t = cur;
        pre->next = t;
        
        return d->next;
    }
};
