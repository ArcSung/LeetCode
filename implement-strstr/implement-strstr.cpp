class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.size() == 0)
            return 0;
        
        for(int i = 0; i < haystack.size(); i++){
            if(haystack.size() - i < needle.size())
                break;
                
            if(haystack[i] == needle[0]){
                if(haystack.compare(i, needle.size(), needle) == 0)
                    return i;
            }
        }
        
        return -1;
    }
};
