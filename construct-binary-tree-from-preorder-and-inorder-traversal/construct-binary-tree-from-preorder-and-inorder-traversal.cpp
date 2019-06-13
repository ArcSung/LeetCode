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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(preorder.size()!=inorder.size()) return NULL;
        int n = preorder.size();
        return buildBT(preorder, inorder, 0, n-1, 0, n-1);
    }
    
    TreeNode *buildBT(vector<int> &preorder, vector<int> &inorder, int s1, int e1, int s2, int e2) {
        if(s1>e1 || s2>e2) return NULL;
        TreeNode *root = new TreeNode(preorder[s1]);
        
        int rootIndex = -1; // root index in inorder
        for(int i=s2; i<=e2; i++) {
            if(inorder[i]==root->val) {
                rootIndex = i;
            }
        }
        if(rootIndex==-1) return NULL;
        int leftTreeSize = rootIndex - s2;
        int rightTreeSize = e2 - rootIndex;
        
        root->left = buildBT(preorder, inorder, s1+1, s1+leftTreeSize, s2, rootIndex-1);
        root->right = buildBT(preorder, inorder, e1-rightTreeSize+1, e1, rootIndex+1, e2);
        return root;
    }
};

int main(void){
	Solution sl;
	vector<int> preorder({3, 9, 20, 15, 7});
	vector<int> inorder({9, 3, 15, 20, 7});

	sl.buildTree(preorder, inorder);

	return true;
}
