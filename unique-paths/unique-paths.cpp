#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<climits>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m<1 || n<1) return 0;
        vector<int> dp(n, 1);
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                dp[j] += dp[j-1];
            }
        }
        return dp[n-1];
    }
};

int main(void){
    Solution sl;

    int ret = sl.uniquePaths(7, 3);

    printf("ret:%d\n", ret);

    return true;
}
