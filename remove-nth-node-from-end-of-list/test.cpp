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

class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {

			ListNode *first = head;

			if(first == NULL || n <= 0 || first->next == NULL)
				return first;

			while(first != NULL){
				int i = 0;
				ListNode *temp_node = first;
				for(i = 0; i < n ; i++){
					if(temp_node->next == NULL)
						break;
					temp_node = temp_node->next;
				}

				if(i < n ){
					return first->next;
				}	
				else if(i == n  && temp_node->next == NULL){
					// next one is the target
					if(n != 1)
						first->next = first->next->next;
					else
						first->next = NULL;
					break;
				}


				first = first->next;
			}

			return head;
		}
};

int main(void){
	Solution sl;
	ListNode a(1);
	ListNode b(2);
	ListNode c(3);
	ListNode d(4);
	ListNode e(5);

	ListNode *head = &a;
	a.next = &b;
	b.next = &c;
	c.next = &d;
	d.next = &e;
	e.next = NULL;

	head = sl.removeNthFromEnd(head, 3);

	while(head != NULL){
		printf("%d\n",head->val);
		head = head->next;
	}

	return true;
}
