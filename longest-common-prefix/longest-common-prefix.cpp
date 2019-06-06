class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        
        string ret;
        
        if(strs.empty())
            return "";
        

        for(int i = 0; i < strs[0].size(); i++){
            for(int j = 1; j < strs.size(); j++){
                if(i >= strs[j].size() || strs[0][i] != strs[j][i])
                    return ret;
            }
            ret.push_back(strs[0][i]);
        }
        
        return ret;
    }
};
