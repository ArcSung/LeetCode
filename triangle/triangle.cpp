#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<climits>

using namespace std;


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int m = triangle[n-1].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX));
        dp[0][0] = triangle[0][0];
        
        for(int i = 1; i < n; i++){
            for(int j = 0; j < triangle[i].size(); j++){
                if(j == 0) dp[i][0] = dp[i-1][0] + triangle[i][0];
                else{
                    //int a = dp[i-1][j] > dp[i-1][j-1]? dp[i-1][j-1]: dp[i-1][j];
                    dp[i][j] = triangle[i][j] + (dp[i-1][j] > dp[i-1][j-1]? dp[i-1][j-1]: dp[i-1][j]);
                }
            }
        }
        
        int ret = INT_MAX;
        for(int i = 0; i < dp.size(); i++)ret = min(ret, dp[n-1][i]);
        
        return ret;
    }
};


int main(void){
    Solution sl;

    vector<vector<int>> triangle = {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    int ret = sl.minimumTotal(triangle);

    printf("ret:%d\n", ret);

    return ret;
}
