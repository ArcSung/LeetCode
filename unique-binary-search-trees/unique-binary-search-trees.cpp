class Solution {
public:
    int numTrees(int n) {
        vector<int> numBST(n+1,0);
        numBST[0] = 1;
        
        for(int i=1; i<=n; i++) {
            for(int j=0; j<i; j++) {
                numBST[i] += numBST[j]*numBST[i-1-j];
            }
        }
        
        return numBST[n];
    }
};
