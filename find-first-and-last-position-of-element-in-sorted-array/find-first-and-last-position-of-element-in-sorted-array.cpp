#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int max = nums.size() - 1, min = 0;
        int start = -1, end = -1;

        while(max >= min){
            int mid = min + (max - min) / 2;
            if(nums[mid] == target){
                min = mid;
                max = mid;
                while(start == -1 || end == -1){
                    if(min == 0)
                        start = min;
                    else if(nums[min - 1] != target)
                        start = min;
                    else
                        min--;

                    if(max == nums.size() - 1)
                        end = max;
                    else if(nums[max + 1] != target)
                        end = max;
                    else
                        max++;
                }
                break;
            }else if(nums[mid] < target)
                min = mid + 1;
            else if(nums[mid] > target)
                max = mid - 1;

        }
        vector<int> ret({start, end});

	printf("%d, %d\n", start, end);

        return ret;
    }
};

int main(void){

	Solution sl;
	vector<int> nums({1});

	sl.searchRange(nums, 1);


	return 0;
}
