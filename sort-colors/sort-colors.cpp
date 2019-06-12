#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {

        vector<int> ret;
	int z_count = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                ret.insert(ret.begin(), 0);
		z_count++;
	    }
            else if(nums[i] == 2)
                ret.push_back(2);
            else{
                ret.insert(ret.begin() + z_count, 1);
	    }
        }
        
        swap(ret, nums);
    }
};


int main(void){
	Solution sl;

	vector<int> nums({2, 0, 2, 1, 1, 0});

	sl.sortColors(nums);

	return true;
}
