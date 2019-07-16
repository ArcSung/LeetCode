#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector> 
#include <algorithm>

using namespace std;

class Solution {
    
    void helper(vector<vector<int>> &ress, vector<int> &res, int start, int n, int k){
        if(res.size() >= k){
            ress.push_back(res);
            return;
        }
        
        for(int i = start; i <= n; i++){
            res.push_back(i);
            helper(ress, res, i + 1, n, k);
            res.erase(res.end()-1);
        }
    }
    
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ress;
        vector<int> res;
        
        helper(ress, res, 1, n, k);
        
        return ress;
        
    }
};

int main(void){
    Solution sl;

    sl.combine(4, 2);

    return true;
}
