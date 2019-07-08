#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
        
        int la = a.size() - 1;
        int lb = b.size() - 1;
        
        int c = 0;
        string ret = "";
        
        while(la >= 0 || lb >= 0 || c > 0){
            int sum = c;
            if(la >= 0){
                sum += a[la] - 48;
                la--;
            }
            
            if(lb >= 0){
                sum += b[lb] - 48;
                lb--;
            }
            
            c = sum / 2;
            ret += sum % 2 + 48;
        }
        
        reverse(ret.begin(), ret.end());
        
        return ret;
   }
};


int main(void){
    Solution sl;

    string s = "1";
    string p = "11";

    string ret = sl.addBinary(s, p);

    printf("ret:%s\n", ret.c_str());
}
