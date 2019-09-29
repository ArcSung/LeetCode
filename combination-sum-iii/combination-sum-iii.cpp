class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n <= 0 || k <= 0)
            return sums;
        
        help( k,  n, 0);
        
        return sums;
    }
    
private:
    vector<int> sum;
    vector<vector<int>> sums;
    
    void help(int k, int n, int c){        
        if(k == 0){
            if(n == 0)
                sums.push_back(sum);
            return;
        }
        
        for(int i = c + 1; i < 10; i++){
            if(n >= i){
                sum.push_back(i);
                help(k - 1, n - i, i);
                sum.pop_back();
            }
        }
    }
};
