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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = NULL;
        ListNode *current = NULL;
        
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        
        if(l1->val > l2->val){
            head = l2;
            l2 = l2->next;
        }else{
            head = l1;
            l1 = l1->next;
        }
        
        current = head;
        
        while(l1 != NULL || l2 != NULL){
            
            if(l1){
                if(!l2){
                    current->next = l1;
                    l1 = l1->next;
                    return head;
                }else if(l1->val > l2->val){
                    current->next = l2;
                    l2 = l2->next;
                }else{
                    current->next = l1;
                    l1 = l1->next;
                }
                
            }else if(l2){
                current->next = l2;
                l2 = l2->next;
                return head;
            }
            

            current = current->next;
        }
        
        return head;
    }
};
