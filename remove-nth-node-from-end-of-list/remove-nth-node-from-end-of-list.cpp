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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode *first = head;
        
        if(first == NULL || n <= 0 || first->next == NULL)
            return NULL;
        
        while(first != NULL){
            int i = 0;
            ListNode *temp_node = first;
            for(i = 0; i < n ; i++){
                if(temp_node->next == NULL)
                    break;
                temp_node = temp_node->next;
            }
            
            if(i < n){
                
                return first->next;
            }
            else if(i == n && temp_node->next == NULL){
                // next one is the target
                if(n == 1)
                    first->next = NULL;
                else
                    first->next = first->next->next;
                break;
            }
                
                
            first = first->next;
        }
        
        return head;
    }
};
