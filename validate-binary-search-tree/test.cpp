#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <stack> 
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode *p = root, *pre = NULL;
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top(); s.pop();
            if (pre && p->val <= pre->val) return false;
            pre = p;
            p = p->right;
        }
        return true;
    }
};

int main(void){
	Solution sl;
	TreeNode a1(5);
	TreeNode a2(1);
	TreeNode a3(4);
	TreeNode a4(3);
	TreeNode a5(6);
	TreeNode a6(4);
	TreeNode a7(3);

	TreeNode *root = &a1;
	a1.left = &a2;
	a1.right = &a3;
	//a2.left = &a4;
	//a2.right = &a5;
	a3.left = &a4;
	a3.right = &a5;

	sl.isValidBST(root);

	return true;
}
