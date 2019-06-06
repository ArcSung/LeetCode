class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        map <int, int> hashMap;
        map <int, int>::iterator iter;
         
        for (int i=0; i<nums.size();i++){
            iter = hashMap.find(target-nums[i]);  
             
            if (iter != hashMap.end()){
                ans.push_back(iter->second);
                ans.push_back(i);
                return ans;
            }
            else
                hashMap.insert(pair<int,int>(nums[i], i)); 
        }
        return ans;
    }
};

