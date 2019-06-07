#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector>
#include <set>
#include <algorithm>    // std::sort
using namespace std; 

int main(void){
	vector<int> nums({1 ,2 , 4, 8, 16, 32, 64, 128});
	int target = 82;
	if (nums.empty() ) return 0;

	sort(nums.begin(), nums.end());

	int res = nums[0] + nums[1] + nums[2] - target;

	for (int k = 0; k < nums.size() - 2; ++k) {
		if (nums[k] > target) break;
		int i = k + 1, j = nums.size() - 1;
		while (i < j) {
			int diff = nums[k] + nums[i] + nums[j] - target;
			if(abs(diff)<abs(res)){
				res = diff;
				printf("k:%d, i:%d, j:%d, res:%d\n", k, i, j, res);
			}

			if(diff == 0)
				return res;
			else if(diff > 0)
				--j;
			else
				++i;
		}
	}

	printf("res:%d \n", res + target);
	return res + target;
}
