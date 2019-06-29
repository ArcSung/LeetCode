#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<stack>
#include<climits>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();

        vector<int> dp(m, INT_MAX);
        dp[0] = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j == 0) dp[j] += grid[i][j];
                else dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[m-1];
    }
};

int main(void){
    Solution sl;

    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1,}, {4, 2, 1}};
    
    int ret = sl.minPathSum(grid);

    printf("ret:%d\n", ret);

    return ret;
}
