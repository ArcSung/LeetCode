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

int main(void){
	Solution sl;
	ListNode a1(1);
	ListNode a2(4);
	ListNode a3(5);
	ListNode b1(1);
	ListNode b2(3);
	ListNode b3(4);
	ListNode c1(2);
	ListNode c2(6);

	ListNode *l1 = &a1;
	a1.next = &a2;
	a2.next = &a3;
	a3.next = NULL;

	ListNode *l2 = &b1;
	b1.next = &b2;
	b2.next = &b3;
	b3.next = NULL;

	ListNode *l3 = &c1;
	c1.next = &c2;
	c2.next = NULL;

	vector<ListNode*> lists;
	lists.push_back(l1);
	lists.push_back(l2);
	lists.push_back(l3);

	ListNode *head = sl.mergeKLists(lists);

	while(head != NULL){
		printf("%d\n",head->val);
		head = head->next;
	}

	return true;
}
