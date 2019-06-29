#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector>
using namespace std;

class Solution {
    public:
        vector<string> findRepeatedDnaSequences(string s) {
            set<string> st, ret;

            for(int i = 0; i + 9 < s.size(); i++){
                string t = s.substr(i, 10);
                if(st.count(t)) ret.insert(t);
                else st.insert(t);
            }
        }
};

int main(void){
	Solution sl;
    

    sl.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");

	return true;
}
