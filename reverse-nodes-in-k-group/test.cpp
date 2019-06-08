#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <stack> 
using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

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

int main(void){
	Solution sl;
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);

	ListNode *l1 = &a1;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	a5.next = NULL;

	ListNode *head = sl.reverseKGroup(l1, 3);

	while(head != NULL){
		printf("%d\n",head->val);
		head = head->next;
	}

	return true;
}
