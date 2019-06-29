class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid.size() == 0 || obstacleGrid[0].size() == 0 || obstacleGrid[0][0] == 1)
            return 0;
        
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        
        vector<long> dp(m, 0);
        dp[0] = 1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if (obstacleGrid[i][j] == 1) dp[j] = 0;
                else if (j > 0) dp[j] += dp[j - 1];
            }
        }
            
        return dp[m - 1];
        
    }
};
