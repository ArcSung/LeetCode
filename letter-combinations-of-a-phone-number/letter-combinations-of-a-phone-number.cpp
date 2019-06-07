class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector <string> puttons({"", "abc", "def", "ghi", "jkl",     
                                "mno", "pqrs", "tuv", "wxyz"});
    
        vector<string> ret;
        
        if (digits.size() < 1)
            return ret;
        
        ret.push_back("");
        
        for(int i = 0; i < digits.size(); i ++){
            int num = digits[i] - '0';
            if(num < 1 || num > 9)
                continue;
            string putton = puttons[num - 1];
            
            if(putton.size() < 3)
                continue;
            
            vector<string> temp_res;
            
            for (int j = 0; j < putton.size(); ++j)
            {
                for (int k = 0; k<ret.size(); ++k)
                {
                    temp_res.push_back(ret[k] + putton[j]);
                }

            }
            ret.swap(temp_res);

        }
        
        return ret;
    }   
};
