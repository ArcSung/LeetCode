#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <queue> 
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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        
        int level = 1;
        
        while(!q.empty()){
            TreeNode *cur = q.front(); q.pop();
            if(cur == NULL){
                level++;
                cur = q.front(); q.pop();
                q.push(NULL);
            }
            
            if(!cur->right && !cur->left)
                break;
                
                
            if(cur->left) q.push(cur->left);
            if(cur->right)q.push(cur->right);

        }
        
        return level;
    }
};

int main(void){
	Solution sl;

    TreeNode *a1 = new TreeNode(3);
    TreeNode *a2 = new TreeNode(9);
    TreeNode *a3 = new TreeNode(20);
    TreeNode *a4 = new TreeNode(15);
    TreeNode *a5 = new TreeNode(7);

    a1->left = a2;
    a1->right = a3;
    a3->left = a4;
    a3->right = a5;

	sl.minDepth(a1);

	return true;
}
