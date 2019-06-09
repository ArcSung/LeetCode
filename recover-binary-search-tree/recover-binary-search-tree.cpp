class Solution {
public:
    void recoverTree(TreeNode* root) {
        if(root == NULL || (root->left==NULL&&root->right==NULL))
            return;
        
    	traversal(root);

        if(firstNode!=NULL&&secondNode!=NULL)
        {
            int temp=firstNode->val;
            firstNode->val=secondNode->val;
            secondNode->val=temp;
        }
        
    }

private:
    TreeNode *firstNode=NULL;
    TreeNode *secondNode=NULL;
    TreeNode *pre=NULL;
    bool flag=false;

    void traversal(TreeNode* root){
        if(root == NULL)
            return;
        
        traversal(root->left);
        
        if(pre!=NULL&&pre->val>root->val&&!flag){
            firstNode=pre;
            flag=true;
            secondNode=root;
        }
        else if(pre!=NULL&&pre->val>root->val&&flag){
            secondNode=root;
        }
        pre=root;
        
        traversal(root->right);

    }
};
