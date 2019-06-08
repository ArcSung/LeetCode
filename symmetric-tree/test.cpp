#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <queue> 
using namespace std;


// * Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

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


int main(void){
	Solution sl;
	TreeNode a1(1);
	TreeNode a2(2);
	TreeNode a3(3);
	TreeNode a4(3);
	TreeNode a5(3);
	TreeNode a6(4);
	TreeNode a7(3);

	TreeNode *root = &a1;
	a1.left = &a2;
	a1.right = &a3;
	//a2.left = &a4;
	//a2.right = &a5;
	//a3.left = &a6;
	//a3.right = &a7;

	sl.isSymmetric(root);

	return true;
}
