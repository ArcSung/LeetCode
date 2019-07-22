#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>

using namespace std;


class Solution {
    public:
        vector<string> fullJustify(vector<string>& words, int maxWidth) {
            vector<string> res;
            int i = 0;
            while (i < words.size()) {
                int j = i, len = 0;
                while (j < words.size() && len + words[j].size() + j - i <= maxWidth) {
                    len += words[j++].size();
                }
                string out;
                int space = maxWidth - len;
                for (int k = i; k < j; ++k) {
                    out += words[k];
                    if (space > 0) {
                        int tmp;
                        if (j == words.size()) { 
                            if (j - k == 1) tmp = space;
                            else tmp = 1;
                        } else {
                            if (j - k - 1 > 0) {
                                if (space % (j - k - 1) == 0) tmp = space / (j - k - 1);
                                else tmp = space / (j - k - 1) + 1;
                            } else tmp = space;
                        }
                        out.append(tmp, ' ');
                        space -= tmp;
                    }
                }
                res.push_back(out);
                i = j;
            }
            return res;
        }
};


int main(void){
    Solution sl;

    vector<string> words = {"This", "is", "an", "example", "of", "text", "justification"};

    vector<string> ret = sl.fullJustify(words, 16);

    for(string s : ret)
        printf("%s\n", s.c_str());

    return true;
}
