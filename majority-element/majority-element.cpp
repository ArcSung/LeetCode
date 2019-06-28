#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector>
using namespace std;

class Solution {
    public:
        int majorityElement(vector<int>& nums) {
            int h = nums.size() - nums.size() / 2;
            int sum = 0;

            for(int i = 0; i < 32; i++){
                int mask = 1 << i;
                int b = 0;

                for(int j = 0; j < nums.size(); j++){
                    b += nums[j] & mask ? 1 : 0;
                }

                if(b >= h)
                    sum += mask;
            }

            return sum;
        }
};

int main(void){
	Solution sl;
    
    vector<int> nums = {-2147483648};

    sl.majorityElement(nums);

	return true;
}
