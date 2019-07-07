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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> levelNodeValues;
        if(!root) return levelNodeValues;

        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        bool dri = true;

        while(!q.empty()) {
            int size = q.size();

            while(size--){
                TreeNode *cur = q.front(); q.pop();

                temp.push_back(cur->val);

                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
            }

            if(!dri)
                reverse(temp.begin(), temp.end());

            levelNodeValues.push_back(temp);
            temp.clear();
            dri = !dri;
        }

        return levelNodeValues;        
    }
};

int main(void){
	Solution sl;
	TreeNode a1(1);
	TreeNode a2(2);
	TreeNode a3(3);
	TreeNode a4(4);
	TreeNode a5(5);
	TreeNode a6(4);
	TreeNode a7(3);

	TreeNode *root = &a1;
	a1.left = &a2;
	a1.right = &a3;
	a2.left = &a4;
	a3.right = &a5;
	//a3.left = &a6;
	//a3.right = &a7;

	sl.zigzagLevelOrder(root);

	return true;
}
