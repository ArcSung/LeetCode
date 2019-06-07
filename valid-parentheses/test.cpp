#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <stack>
#include <unordered_map>
#include <algorithm>    // std::sort
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, int> parentheses({{'(', 0}, {')', 1},
                                          {'{', 0},{'}', 1},
                                          {'[', 0},{']', 1}});
        
        stack<char> parenth_stack;
        int state = 0;
        
        for(char c: s){
            unordered_map<char, int>::iterator it = parentheses.find(c);
            if(it != parentheses.end()){
                if(it->second == 1){
                    if(parenth_stack.empty())
                        return false;
                    
                    if((it->first == ')' && parenth_stack.top() == '(') 
                      || (it->first == '}' && parenth_stack.top() == '{')
                      || (it->first == ']' && parenth_stack.top() == '['))
                        parenth_stack.pop();
                    else
                        return false;
                }else
                    parenth_stack.push(it->first);
                
            }
        }
        
        if(parenth_stack.empty())
            return true;
        else
            return false;
    }
};

int main(void){
	Solution sl;

	sl.isValid("()");

	return true;
}
