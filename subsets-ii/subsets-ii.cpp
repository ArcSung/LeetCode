#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector>
using namespace std;

class Solution {
    void help(vector<vector<int>> &ret, vector<int> &n, vector<int>& nums, int s){
        ret.push_back(n);

        for(int i = s; i < nums.size(); i++){
            if(i != s && nums[i] == nums[i-1])
                continue;
            
            n.push_back(nums[i]);
            help(ret, n, nums, i + 1);
            n.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> n;
        sort(nums.begin(), nums.end());
        help(ret, n, nums, 0);

        return ret;
    }
};

int main(void){
	Solution sl;
    
    vector<int> nums = {1, 2, 3};

    sl.subsetsWithDup(nums);

	return true;
}
