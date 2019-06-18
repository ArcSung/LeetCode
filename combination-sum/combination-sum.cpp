#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if(candidates.empty())
            return finSol;
        
        sort(candidates.begin(), candidates.end());
        findSum(candidates, target, 0);
        
        return finSol;
    }
    
private:
    vector<int> sol;
    vector<vector<int>> finSol;
    
    void findSum(vector<int>& candidates, int target, int start){
        if(target == 0){
            finSol.push_back(sol);
            return;
        }
        
        for(int i = start; i < candidates.size(); i++){
               if(candidates[i] <= target){
                   sol.push_back(candidates[i]);
                   findSum(candidates, target - candidates[i], i);
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
