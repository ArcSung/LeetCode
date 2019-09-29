#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include <algorithm>
#include <climits>


using namespace std; 

class Solution {
public:
  vector<int> majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int l = 0;
        vector<int> ret;
        int m = nums.size() / 3;
        
        if(nums.size() == 0)
            return ret;
        if(nums.size() == 1){
            ret.push_back(nums[0]);
            return ret;
        }
        
        int c = nums[0];
        nums.push_back(INT_MAX);
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > c){
                if(i - l > m)
                    ret.push_back(c);
                    
                c = nums[i];
                l = i;
            }
        }
        
        return ret;
    }
};

int main(void){
    Solution sl;

    vector<int> nums = {1, 3, 3, 2, 3, 2, 2, 1};

    sl.majorityElement(nums);

    return 0;

}
