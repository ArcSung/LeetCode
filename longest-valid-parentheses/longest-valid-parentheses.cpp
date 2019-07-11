#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<stack>
#include<string>

using namespace std;


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<pair<int, char>> st;
        int l = 0, res = 0;

        for(int i = 0; i < s.size(); i ++){
            if(s[i] == '(')
                st.push(make_pair(i, s[i]));
            else{
                if(st.empty() || st.top().second == ')')
                    st.push(make_pair(i, s[i]));
                else{
                    st.pop();
                    if(st.empty())
                        l = i + 1;
                    else
                        l = i - st.top().first;

                    res = max(l, res);
                }
                    
            }
            
        }

        return res;
        
    }
};

int main(void){
    Solution sl;

    int ret = sl.longestValidParentheses(")()()");

    printf("ret:%d\n", ret);

    return true;
}
