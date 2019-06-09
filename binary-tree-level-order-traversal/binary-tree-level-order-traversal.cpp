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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> levelNodeValues;
        if(!root) return levelNodeValues;
        
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int curLevel = 0;
        
        while(!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            
            if(!cur) {
                curLevel++;
                if(!q.empty()) q.push(NULL);
                continue;
            }
            
            if(curLevel==levelNodeValues.size())
                levelNodeValues.push_back(vector<int>(0,0));
            levelNodeValues[curLevel].push_back(cur->val);
            
            if(cur->left) q.push(cur->left);
            if(cur->right) q.push(cur->right);
        }
        
        return levelNodeValues;        
    }
};

int main(void){
	Solution sl;
	TreeNode a1(3);
	TreeNode a2(9);
	TreeNode a3(20);
	TreeNode a4(15);
	TreeNode a5(7);
	TreeNode a6(4);
	TreeNode a7(3);

	TreeNode *root = &a1;
	a1.left = &a2;
	a1.right = &a3;
	a3.left = &a4;
	a3.right = &a5;
	//a3.left = &a6;
	//a3.right = &a7;

	sl.levelOrder(root);

	return true;
}
