#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<climits>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  int DFS(TreeNode* root){
        if(!root) 
            return 0;
        
        int left = DFS(root->left);
        if(left < 0) return -1;
        
        int right = DFS(root->right);
        if(right < 0) return -1;
        
        if(abs(left - right) > 1) 
            return -1;
        else 
            return max(left, right) + 1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        
        if(DFS(root) < 0) return false;
        
        return true;
    }
};

int main(void){
    Solution sl;

    TreeNode *root = new TreeNode(1);
    TreeNode *r1 = new TreeNode(2);
    TreeNode *r2 = new TreeNode(3);

    root->right = r1;
    r1->right = r2;

    bool ret = sl.isBalanced(root);

    printf("ret:%d\n", ret);

    return true;
}
