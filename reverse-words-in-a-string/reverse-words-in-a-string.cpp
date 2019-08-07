class Solution {
public:
    string reverseWords(string s) {        
        int isWord = 0;
        string cur = "";
        string res = "";
        s += ' ';
        
        for(char &c : s){
            if(c == ' ' && isWord){
                if(cur.size() > 0){
                    if(res.size() == 0)
                        res = cur;
                    else
                        res = cur + " " + res;
                    cur.erase();
                }
                
                isWord == 0;
            }
            else if(c != ' '){
                isWord = 1;
                cur += c;
            }
        }
        
        return res;
    }
};
