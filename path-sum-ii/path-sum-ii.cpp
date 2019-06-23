#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;


//  Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> path;
        vector<vector<int>> allPath;
        
        findPathSum(root, path, allPath, sum);
        
        return allPath;
    }
    
private:
    void findPathSum(TreeNode* root, vector<int> path, vector<vector<int>> allPath, int sum){
        if(root == NULL) return;
    
        path.push_back(root->val);
        sum -= root->val;
        
        if(!root->left && !root->right){
           if(sum == 0)
                allPath.push_back(path);
        }else{
            if(root->left) findPathSum(root->left, path, allPath, sum);
            if(root->right) findPathSum(root->right, path, allPath, sum);
        }
    
        path.pop_back();
    
        return;
    }
};

int main(void){
    Solution sl;
    
    TreeNode *a1 = new TreeNode(5);
    TreeNode *a2 = new TreeNode(4);
    TreeNode *a3 = new TreeNode(8);
    TreeNode *a4 = new TreeNode(11);
    TreeNode *a5 = new TreeNode(13);
    TreeNode *a6 = new TreeNode(4);
    TreeNode *a7 = new TreeNode(7);
    TreeNode *a8 = new TreeNode(2);
    TreeNode *a9 = new TreeNode(5);
    TreeNode *a10 = new TreeNode(1);

    a1->left = a2;
    a1->right = a3;

    a2->left = a4;

    a3->left = a5;
    a3->right = a6;

    a4->left = a7;
    a4->right = a8;

    a6->left = a9;
    a6->right = a10;

    sl.pathSum(a1, 22);
}
