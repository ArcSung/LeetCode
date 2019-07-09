class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        
        if(m == 0)
            return;
        
        int n = matrix[0].size();
        unordered_set<int> si;
        unordered_set<int> sj;
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(matrix[i][j] == 0){
                    si.insert(i);
                    sj.insert(j);
                }
            }
        }
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(si.count(i) || sj.count(j)){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};
