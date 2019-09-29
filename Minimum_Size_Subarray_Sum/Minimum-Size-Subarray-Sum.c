#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<climits>

using namespace std; 

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int res = INT_MAX;
        int sum = 0;
        int l = 0;
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            
            while(l <= i && sum >= s){
                res = min(res, i - l + 1);
                sum -= nums[l++];
            }
        }
        
        return res == INT_MAX ? 0: res;
    }
};


int main(void){
    Solution sl;

    vector<int> nums = {2, 3, 1, 2, 4, 3};

    return sl.minSubArrayLen(7, nums);

}
