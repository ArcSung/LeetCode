#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int max = nums.size() - 1, min = 0;
        
        while(max >= min){
            int mid = min + (max - min) / 2;
            
            if(nums[mid] == target)
                return mid;
            
            if(nums[mid] < nums[max]){
                if(target > nums[mid] && target <= nums[max]){
                    min = mid + 1;
                }else
                    max = mid - 1;
            }else{
                if(nums[mid] > target && nums[min] <= target){
                    max = mid - 1;
                }else
                    min = mid + 1;
            }
        }
        return -1;
    }
};

int main(void){

	Solution sl;
	//vector<int> nums({4, 5, 6, 7, 0, 1, 2});
	vector<int> nums({1, 3});

	int ret = sl.search(nums, 2);

	printf("ret:%d\n", ret);

	return ret;
}
