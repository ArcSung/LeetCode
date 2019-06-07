class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        if (nums.size() < 3) return INT_MAX;   
        sort(nums.begin(), nums.end());
                
        int res = nums[0] + nums[1] + nums[2] - target;

        for (int k = 0; k < nums.size() - 2; k++) {
            int i = k + 1, j = nums.size() - 1;
            while (i < j) {
                int diff = nums[k] + nums[i] + nums[j] - target;
                if(abs(diff)<abs(res)) res = diff;
                
                if(diff == 0)
                    break;
                else if(diff > 0)
                    --j;
                else
                    ++i;
            }
        }
        return res + target;
    }
};
