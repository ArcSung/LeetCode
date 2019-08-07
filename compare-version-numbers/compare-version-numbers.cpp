#include<stdlib.h>
#include<stdio.h>
#include<string>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1 = version1.size();
        int s2 = version2.size();
        int i1 = 0, i2 = 0;
        int v1 = 0, v2 = 0;
        
        while(i1 < s1 || i2 < s2){
            while( i1 < s1 && version1[i1] != '.'){
                v1 = v1 * 10 + version1[i1] - '0';
                i1++;
            }
            
            while( i2 < s2 && version2[i2] != '.'){
                v2 = v2 * 10 + version2[i2] - '0';
                i2++;
            }
            
            if(v1 > v2) return 1;
            else if(v1 < v2) return -1;
            
            i1++;
            i2++;
            v1 = v2 = 0;
        }
        
        return 0;
    }
};


int main(void){
    Solution sl;

    sl.compareVersion("0", "1");

    return true;

}
