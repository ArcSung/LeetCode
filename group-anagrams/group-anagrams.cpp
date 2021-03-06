class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ret;
        unordered_map<string, vector<string>> map;
        for(string s: strs){
            string t = s;
            sort(t.begin(), t.end());
            map[t].push_back(s);
        }
        
        for(auto s: map)
            ret.push_back(s.second);
        
        return ret;
    }
};
