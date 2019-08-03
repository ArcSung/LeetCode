#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


static TreeNode* makeTree(vector<int> nums, int index){
    if(index > nums.size() - 1 || nums[index] == -1)
        return NULL;

   TreeNode *root = new TreeNode(nums[index]);
   root->left = makeTree(nums, index * 2 + 1);
   root->right = makeTree(nums, index * 2 + 2);

    return root;
}

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root->left) flatten(root->left);
        if(root->right) flatten(root->right);
        
        TreeNode *temp = root->right;
        
        root->right = root->left;
        
        root->left = NULL;

        while(root->right) root = root->right;

        root->right = temp;
        
        return;
    }
};

int main(void){
    Solution sl;
    vector<int> nums = {1, 2, 5, 3, 4, -1, 6};

    TreeNode* root = makeTree(nums, 0);

    
    sl.flatten(root);


    return true;
}
