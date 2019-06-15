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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k < 1)
            return head;
        
        ListNode* cur = head;
        int len = 1;
            
        while(cur->next != NULL){
            ++len;
            cur = cur->next;
        }

        cur->next = head;
        
        k = len - k % len;
        
        for(int i = 0; i < k; i++){
            cur = cur->next;
        }
            
        head = cur->next;
        cur->next = NULL;
        
        return head;
    }
};

int main(void){
    Solution sl;
    ListNode *a1 = new ListNode(1);
    ListNode *a2 = new ListNode(2);
    ListNode *a3 = new ListNode(3);
    ListNode *a4 = new ListNode(4);
    ListNode *a5 = new ListNode(5);

    a1->next = a2;
    //a2->next = a3;
    //a3->next = a4;
    //a4->next = a5;

    ListNode *head = sl.rotateRight(a1, 1);

    while(head != NULL){
        printf("%d\n", head->val);
        head = head->next;
    }

    return 0;
}
