#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector>
#include <set>
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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy, *cur = head;
        
        while(cur && cur->next) {
            prev->next = cur->next;
            cur->next = cur->next->next;
            prev->next->next = cur;
            prev = cur;
            cur = cur->next;
        }
        
        return dummy->next;
    }
};

int main(void){
	Solution sl;
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);

	ListNode *l1 = &a1;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = NULL;

	ListNode *head = sl.swapPairs(l1);

	while(head != NULL){
		printf("%d\n",head->val);
		head = head->next;
	}

	return true;
}
