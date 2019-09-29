#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std; 

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ret;
        
        if(nums.size() == 0)
            return ret;
        
        int start = 0;
        
        
        for(int i = 1; i <= nums.size(); i++){
            if(i == nums.size() || nums[i] != nums[i - 1] + 1){
                ret.push_back(start == i - 1 ? to_string(nums[start])
                             :to_string(nums[start]) + "->" + to_string(nums[i - 1]));
                
                start = i;
            }
        }
        
        return ret;
    }
};

int main(void){
    Solution sl;

    vector<int> nums = {0, 2, 3, 4, 6, 8, 9};

    sl.summaryRanges(nums);

    return 0;

}
