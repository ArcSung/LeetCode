class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        if (nums.size() < 4) return {};
        
        for (int k = 0; k < nums.size(); ++k) {
            
            for(int z = k + 1; z < nums.size() - 2; z++){
                int i = z + 1, j = nums.size() - 1;
                int diff = target - nums[k] - nums[z];
                while (i < j) {
                    if (nums[i] + nums[j] == diff) {
                        res.insert({nums[k],nums[z], nums[i], nums[j]});
                        ++i; --j;
                } else if (nums[i] + nums[j] < diff) ++i;
                    else --j;
                }
            }
            
        }
        return vector<vector<int>>(res.begin(), res.end());
 
    }
};
