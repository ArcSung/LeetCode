#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector> 
using namespace std;


// * Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL || (root->left==NULL&&root->right==NULL))
            return;
        
    	traversal(root);

        if(firstNode!=NULL&&secondNode!=NULL)
        {
            int temp=firstNode->val;
            firstNode->val=secondNode->val;
            secondNode->val=temp;
        }
        
    }

private:
    TreeNode *firstNode=NULL;
    TreeNode *secondNode=NULL;
    TreeNode *pre=NULL;
    bool flag=false;

    void traversal(TreeNode* root){
        if(root == NULL)
            return;
        
        traversal(root->left);
        
        if(pre!=NULL&&pre->val>root->val&&!flag){
            firstNode=pre;
            flag=true;
            secondNode=root;
        }
        else if(pre!=NULL&&pre->val>root->val&&flag){
            secondNode=root;
        }
        pre=root;
        
        traversal(root->right);

    }
};

int main(void){
	Solution sl;
	TreeNode a(1);
	TreeNode b(3);
	TreeNode c(2);

	a.left = &b;
	b.right = &c;

	sl.recoverTree(&a);

	return true;
}
