#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector>
#include <set>
#include <algorithm>    // std::sort
using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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

int main(void){
	Solution sl;
	ListNode a1(-9);
	ListNode a2(3);
	ListNode a3(4);
	ListNode b1(5);
	ListNode b2(7);
	ListNode b3(4);

	ListNode *l1 = &a1;
	a1.next = &a2;
	a2.next = NULL;
	a3.next = NULL;

	ListNode *l2 = &b1;
	b1.next = &b2;
	b2.next = NULL;
	b3.next = NULL;

	ListNode *head = sl.mergeTwoLists(l1, l2);

	while(head != NULL){
		printf("%d\n",head->val);
		head = head->next;
	}

	return true;
}
