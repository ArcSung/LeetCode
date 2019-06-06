class Solution {
public:
    int romanToInt(string s) {
        if(s.empty()) return 0;
        unordered_map<char,int> ht({{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}});
        int ret = 0;
        for(int i=0; i<s.size(); i++) {
            if(ht.count(s[i])==0) return 0;
            ret += ht[s[i]];
            if(i!=0 && ht[s[i]]>ht[s[i-1]])
                ret -= 2*ht[s[i-1]];
        }
        return ret;
    }
};
