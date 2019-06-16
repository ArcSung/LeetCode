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

//Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        return buildTree(head);
    }
    
    TreeNode* buildTree(ListNode* head) {
        if(head == NULL) 
            return NULL;

        if(head->next == NULL)
            return new TreeNode(head->val);
        
        ListNode *pre = head;
        ListNode *slow = head;
        ListNode *fast = head;
        
        while(fast->next && fast->next->next){
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        
        TreeNode *root;
        if(fast !== slow)
            root  = new TreeNode(slow->val);
        else
            root  = new TreeNode(slow->next->val);
        
        pre->next = NULL;
        
        root->left = buildTree(head);
        root->right = buildTree(slow->next);
        
        return root;
    }
};

int main(void){
    Solution sl;
    ListNode *a1 = new ListNode(-10);
    ListNode *a2 = new ListNode(-3);
    ListNode *a3 = new ListNode(0);
    ListNode *a4 = new ListNode(5);
    ListNode *a5 = new ListNode(9);

    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;

    sl.sortedListToBST(a1);

    return 0;
}
