/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        ret.clear();
        traversal(root);
        return ret;
    }
private:
    vector<int> ret;
    void traversal(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        traversal(root->left);
        ret.push_back(root->val);
        traversal(root->right);
    }
};
