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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return travel(p, q);
    }

private:
    bool travel(TreeNode* p, TreeNode* q){
        if((p == NULL && q != NULL) ||
          (p != NULL && q == NULL))
            return false;
        else if(p == NULL && q == NULL)
            return true;
        
        if(p->val != q->val)
            return false;
        
        if(travel(p->right, q->right) && travel(p->left, q->left)){
            return true;
        }else
            return false;
        
    }
};
