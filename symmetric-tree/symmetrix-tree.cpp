
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;

        queue<TreeNode*> ql, qr;
        ql.push(root->left);
        qr.push(root->right);
        while(!ql.empty() && !qr.empty()){
            TreeNode* tl = ql.front(); ql.pop();
            TreeNode* tr = qr.front(); qr.pop();

            if(!tl && !tr)
                continue;

            if((!tl && tr) || (tl && !tr))
                return false;

            if(tl->val != tr->val)
                return false;

            ql.push(tl->left);
            qr.push(tr->right);
            ql.push(tl->right);
            qr.push(tr->left);
        }

        if(!ql.empty() || !qr.empty()) return false;

        return true;
    }
};
