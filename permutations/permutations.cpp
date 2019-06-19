class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> finSol;
        vector<int> sol;
        vector<bool> used(nums.size(), false);
        
        if(nums.empty())
            return finSol;
        
        findSol(nums, sol, used, finSol);
        
        return finSol;
    }
    
private:
    void findSol(vector<int>& nums, vector<int> &sol,  vector<bool> &used, vector<vector<int>> &finSol){
        if(sol.size() == nums.size()){
            finSol.push_back(sol);
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(used[i] == true) continue;
            
            sol.push_back(nums[i]);
            used[i] = true;
            findSol(nums, sol, used, finSol);
            used[i] = false;
            sol.pop_back();
        }
    }
};
