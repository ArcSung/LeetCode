#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<queue>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

static TreeNode* makeTree(vector<int> nums, int index){
    if(index > nums.size() - 1 || nums[index] == -1)
        return NULL;

   TreeNode *root = new TreeNode(nums[index]);
   root->left = makeTree(nums, index * 2 + 1);
   root->right = makeTree(nums, index * 2 + 2);

    return root;
}

class BSTIterator {
private:
    queue<int> qu;
    void traversal(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        traversal(root->left);
        qu.push(root->val);
        traversal(root->right);
    }
public:

    BSTIterator(TreeNode* root) {
        traversal(root);
    }
    
    /** @return the next smallest number */
    int next() {
        int ret = qu.front();
        qu.pop();
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !qu.empty();
    }


};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

int main(void){
    TreeNode *root = makeTree(vector<int>{7, 3, 15, -1, -1, 9, 20}, 0);

    BSTIterator bstIt(root);
    printf("Next:%d\n", bstIt.next());
    printf("Next:%d\n", bstIt.next());
    printf("HasNext:%d\n", bstIt.hasNext());
    printf("Next:%d\n", bstIt.next());
    printf("HasNext:%d\n", bstIt.hasNext());
    printf("Next:%d\n", bstIt.next());
    printf("HasNext:%d\n", bstIt.hasNext());
    printf("Next:%d\n", bstIt.next());
    printf("HasNext:%d\n", bstIt.hasNext());
    
    return 0;
}
