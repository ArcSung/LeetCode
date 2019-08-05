#include<stdlib.h>
#include<stdio.h>
#include<string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {        
        int left = 0, right = s.size() - 1 ;
        while (left < right) {
            if (!isalnum(s[left])) ++left;
            else if (!isalnum(s[right])) --right;
            else if ((s[left] + 32 - 'a') %32 != (s[right] + 32 - 'a') % 32) return false;
            else {
                ++left; --right;
            }
        }
        return true;
    }
};


int main(void){
    Solution sl;

    sl.isPalindrome("0P");

    return true;
}
