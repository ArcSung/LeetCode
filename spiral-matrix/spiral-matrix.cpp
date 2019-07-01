class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return ret;
        
        if(matrix.size() == 1)
            return matrix[0];
        
        int m = matrix[0].size();
        int n = matrix.size();
        int d = 0;
        int is = 0, ie = m - 1, js = 0, je = n - 1;
        int j = 0, i = 0;
        
        for(int s = 0; s < m*n; s++){
            ret.push_back(matrix[j][i]);
            if(d == 0){
                if(i == ie){
                    d=1;
                    js+=1;
                    j=js;
                }else i++;
            }else if(d == 1){
                if(j == je){
                    d=2;
                    ie -= 1;
                    i = ie;
                }else j++;
            }else if(d == 2){
                if(i == is){
                    d=3;
                    je -= 1;
                    j = je;
                }else i--;
            }else if(d == 3){
                if(j == js){
                    d=0;
                    is += 1;
                    i = is;
                }else j--;
            }
            
        }
        
        return ret;
    }
};
