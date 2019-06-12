#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector>
#include <climits>
#include <algorithm>    // std::sort
using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
	if(!head || !head->next)
	    return head;

        ListNode* pre = head, *mid = head, *end = head;
        
        while(end && end->next){
            pre = mid;
            mid = mid->next;
            end = end->next->next;
        }
        
        pre->next = NULL;

        return merge(sortList(head), sortList(mid));
    }
private:
    ListNode* merge(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = merge(l1->next, l2);
            return l1;
        } else {
            l2->next = merge(l1, l2->next);
            return l2;
        }
    }
};

int main(void){
	Solution sl;
	ListNode a1(4);
	ListNode a2(2);
	ListNode a3(1);
	ListNode a4(3);

	ListNode *l1 = &a1;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;

	ListNode *head = sl.sortList(l1);

	while(head != NULL){
		printf("%d\n",head->val);
		head = head->next;
	}

	return true;
}
