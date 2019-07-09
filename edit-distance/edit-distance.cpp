#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
    public:
        int minDistance(string word1, string word2) {
            int s1 = word1.size();
            int s2 = word2.size();
       
            if(!s2) return s1;
            if(!s1) return s2;

            int dp[s1+1][s2+1];

            for(int i = 0; i <= s1; i++) dp[i][0] = i;
            for(int i = 0; i <= s2; i++) dp[0][i] = i;

            for(int i = 1; i <= s1; i++){
                for(int j = 1; j <= s2; j++){
                    if(word1[i - 1] == word2[j - 1])
                        dp[i][j] = dp[i-1][j-1];
                    else
                        dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1])) + 1;
                }
            }

            return dp[s1][s2];
        }
};


int main(void){
    Solution sl;

    string s = "horse";
    string p = "ros";

    int ret = sl.minDistance(s, p);

    printf("ret:%d\n", ret);
}
