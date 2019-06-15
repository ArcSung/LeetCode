#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        return buildTree(nums, 0, nums.size() - 1);
    }
    
    TreeNode* buildTree(vector<int> &nums, int min, int max){
        if(max < min) 
            return NULL;
        
        int mid = min + (max - min) /2;
        
        TreeNode *root = new TreeNode(nums[mid]);
        
        root->left = buildTree(nums, min, mid - 1);
        root->right = buildTree(nums, mid + 1, max);

        return root;
    }
};

int main(void){
    Solution sl;
    vector<int> nums = {-10, -3, 0, 5, 9};
    sl.sortedArrayToBST(nums);

    return 0;
}
