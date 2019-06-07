#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector>
#include <set>
#include <algorithm>    // std::sort
using namespace std; 

int main(void){
	vector<int> nums({1 ,-2 , -5, -4, -3, 3, 3, 5});
	int target = -11;

	vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        if (nums.size() < 4) return {};

        for (int k = 0; k < nums.size(); ++k) {

            for(int z = k + 1; z < nums.size() - 2; z++){
                int i = z + 1, j = nums.size() - 1;
                int diff = target - nums[k] - nums[z];
                while (i < j) {
                    if (nums[i] + nums[j] == diff) {
                        res.push_back({nums[k],nums[z], nums[i], nums[j]});
                        ++i; --j;
                } else if (nums[i] + nums[j] < diff) ++i;
                    else --j;
                }
            }

        }
        return true;
}
