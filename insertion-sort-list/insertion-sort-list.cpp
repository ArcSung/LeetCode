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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *newHead = new ListNode(INT_MIN);

        while(head) {
            ListNode *cur = head;
            ListNode *new_cur = newHead;
            head = head->next;

            while(new_cur->next && new_cur->next->val<=cur->val)
                new_cur = new_cur->next;

            cur->next = new_cur->next;
            new_cur->next = cur;

        }

        head = newHead->next;
        delete newHead;
        return head;
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

	ListNode *head = sl.insertionSortList(l1);

	while(head != NULL){
		printf("%d\n",head->val);
		head = head->next;
	}

	return true;
}
