
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(!nums.size())
            return 0;
        
        int max = 1;
        vector<int> dp(nums.size(), 1);
        
        for(int i = 0; i < nums.size(); i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j] && dp[j] >= dp[i]){
                    dp[i] = dp[j]+1;
                    if(dp[i] > max)
                        max = dp[i];
                }
            }
        }
        
        
        return max;
    }
};


int main() {
    vector<int> nums = {10, 22, 9, 33, 21, 50, 41, 60, 80};
        
    int ret = Solution().lengthOfLIS(nums);

    printf("ret:%d\n", ret);

    return 0;
}
