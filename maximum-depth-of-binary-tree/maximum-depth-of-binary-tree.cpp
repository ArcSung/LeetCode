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
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        
        int depth = 0;
        queue<TreeNode*> cur_q;
        queue<TreeNode*> next_q;
        
        cur_q.push(root);
        
        while(!cur_q.empty()){
            while(!cur_q.empty()){
                TreeNode* root = cur_q.front(); cur_q.pop();
                
                if(root->left) next_q.push(root->left);
                if(root->right) next_q.push(root->right);
            }
            
            swap(cur_q, next_q);
            
            depth++;
        }
        
        return depth;
    }
};
