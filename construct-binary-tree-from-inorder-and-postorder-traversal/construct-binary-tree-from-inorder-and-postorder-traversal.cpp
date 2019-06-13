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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.size()!=inorder.size()) return NULL;
        int n = postorder.size();
        return buildBT(inorder, postorder, 0, n-1, 0, n-1);
    }
    
    TreeNode *buildBT(vector<int> &inorder, vector<int> &postorder, int si, int ei, int pi, int pe) {
        if(si>ei || pi>pe) return NULL;
        TreeNode *root = new TreeNode(postorder[pe]);

        int rootIndex = -1; // root index in inorder
        for(int i = si; i <= ei; i++) {
            if(inorder[i] == root->val) {
                rootIndex = i;
                break;
            }
        }
        
        if(rootIndex==-1) return NULL;
	int leftSize = rootIndex - si;
	int rightSize = ei - rootIndex;
        
        root->left = buildBT(inorder, postorder, si, rootIndex - 1, pi, pi + leftSize - 1);
        root->right = buildBT(inorder, postorder, rootIndex + 1, ei, pe - rightSize , pe - 1);
        
        return root;
    }
};

int main(void){
	Solution sl;
	vector<int> inorder({9, 3, 15, 20, 7});
	vector<int> postorder({9, 15, 7, 20, 3});

	sl.buildTree(inorder, postorder);

	return true;
}
