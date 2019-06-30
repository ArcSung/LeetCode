#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>
#include <algorithm>

using namespace std;


class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.empty() || num2.empty()) return "";
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string ret(num1.size()+num2.size(),'0');
        
        for(int j=0; j<num2.size(); j++) {
            int carry = 0;
            int val = num2[j] - '0';
            for(int i=0; i<num1.size(); i++) {
                carry += ((num1[i]-'0')*val + (ret[i+j]-'0'));
                ret[i+j] = carry%10 + '0';
                carry /= 10;
            }
            if(carry!=0) ret[num1.size()+j] = carry + '0';
        }
        reverse(ret.begin(),ret.end());
        
        int count = 0;
        while(count<ret.size()-1 && ret[count]=='0') count++;
        ret.erase(0,count);
        return ret;
    }
};


int main(void){
    Solution sl;

    sl.multiply("123", "456");

    return true;
}
