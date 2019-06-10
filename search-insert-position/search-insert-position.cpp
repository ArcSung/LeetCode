class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int max = nums.size() - 1;
        int min = 0;
            
        while(max >= min){
            int mid = min + (max - min)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] < target)
                min = mid + 1;
            else if(nums[mid] > target)
                max = mid - 1;
        }
            
        return min;
    }
};
