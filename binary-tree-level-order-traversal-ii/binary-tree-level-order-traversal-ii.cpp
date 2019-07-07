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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> levelNodeValues;
        if(!root) return levelNodeValues;
        
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        
        while(!q.empty()) {
            int size = q.size();
              
            while(size--){
                TreeNode *cur = q.front(); q.pop();
                temp.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }
              
            levelNodeValues.insert(levelNodeValues.begin(), temp);
            temp.clear();
        }
        
        return levelNodeValues;        
    }
};
