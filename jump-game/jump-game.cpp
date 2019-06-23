class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIndex = 0;
        int n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(maxIndex > n || i > maxIndex)
                break;
            
            maxIndex = max(maxIndex, i + nums[i]);
        }
        
        if(maxIndex >= n - 1)
            return true;
        else
            return false;
    }
};
