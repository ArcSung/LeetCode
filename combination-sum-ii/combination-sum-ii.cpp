#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> finSol;
        vector<int> sol;
        
        if(candidates.empty())
            return finSol;
        
        sort(candidates.begin(), candidates.end());
        
        findSum(candidates, 0, target, sol, finSol);
        
        return finSol;
    }
    
private:
    void findSum(vector<int>& candidates, int start, int target, vector<int>& sol, vector<vector<int>> &finSol){
        if(target < 0)
            return;
        
        if(target == 0){
            finSol.push_back(sol);
            return;
        }
    
        for(int i = start; i < candidates.size(); i++){
            if(i != start && candidates[i] == candidates[i - 1]) continue;
            if(candidates[i] <= target){
                sol.push_back(candidates[i]);
                findSum(candidates, i + 1, target - candidates[i], sol, finSol);
                sol.pop_back();
            }
        }
    }
};

int main(void){
    Solution sl;
    vector<int> candidates({2, 3, 6, 7});

    sl.combinationSum(candidates, 7);

    return true;
}
