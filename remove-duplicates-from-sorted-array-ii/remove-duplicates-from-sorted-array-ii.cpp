#include<vector>

using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() < 3) return nums.size();

        int len = 1;

        for(int i = 2; i<nums.size();i++){
            if(nums[i]!=nums[len-1]){
                nums[++len] = nums[i];
            }
        }

        return len + 1;
    }
};


int main(void){
    Solution sl;
    
    vector<int>nums = {0,0,1,1,1,1,2,3,3};

    sl.removeDuplicates(nums);

    return true;
}
