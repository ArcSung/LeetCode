#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;


//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *d = new ListNode(-1);
        d->next = head;
    
        ListNode *pre = d, *cur = head;
        
        while(pre->next && pre->next->val < x) pre = pre->next;

        cur = pre;
        while(cur->next){
            if(cur->next->val >= x){
                cur = cur->next;
            }else{
                ListNode *t = cur->next;
                cur->next = t->next;
                t->next = pre->next;
                pre->next = t;
                pre = pre->next;
            }
        }
        
        return d->next;
    }
};

int main(void){
    Solution sl;
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(4);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(2);
    ListNode *a5 = new ListNode(5);
    ListNode *a6 = new ListNode(2);

    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    a5->next = a6;

    ListNode *head = sl.partition(a1, 3);

    while(head != NULL){
        printf("%d\n", head->val);
        head = head->next;
    }

    return 0;
}
