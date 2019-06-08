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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = NULL;
        ListNode *current = NULL;
        

        
        while(1){
            int min_val = INT_MAX;
            int min_index = -1;
            
            for(int i = 0; i < lists.size(); i++){
                ListNode *temp = lists[i];
                
                if(temp == NULL)
                    continue;
                
                if(temp->val < min_val){
                    min_val = temp->val;
                    min_index = i;
                }
            }
            
            if(min_index != -1){
                if(head == NULL){
                    head = lists[min_index];
                    current = head;
                }else{
                    current->next =  lists[min_index];
                    current = current->next;
                }
                lists[min_index] = lists[min_index]->next;
            }else break;
        }
        
        return head;
    }
};
