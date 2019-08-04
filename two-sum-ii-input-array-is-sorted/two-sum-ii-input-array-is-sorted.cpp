class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size() - 1;
        vector<int> ret;
        
        while(r > l){
            if(numbers[l] + numbers[r] == target){
                ret.push_back(l+1);
                ret.push_back(r+1);
                break;
            }else if(numbers[l] + numbers[r] > target)
                r--;
            else
                l++;
        }
        
        return ret;
    }
};
