#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        N = n;
        backtrack("", 0, 0);
        
        return ret;
    }
private:
    int N;
    vector<string> ret;
    void backtrack(string S, int left, int right){
        if(S.size() == 2 * N){
	    printf("%s\n", S.c_str());
            ret.push_back(S);
            return;
        }
        
        if(left < N)
            backtrack(S+'(', left+1, right);
        
        if(right < left)
            backtrack(S+')', left, right+1);
        
        return;
    }
};

int main(void){
	Solution sl;

	sl.generateParenthesis(3);

	return true;
}
