#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int min = 0;
        int max = nums.size() - 1;
        
        while(max > min){
            int mid = min + (max - min)/2;
            
            if(nums[mid] > nums[mid + 1] ) max = mid;
            else min = mid + 1;
        }
        
        return min;
    }
};

int main(void){
    Solution sl;

    vector<int> nums = {3, 2, 1};

    sl.findPeakElement(nums);

    return true;
}
