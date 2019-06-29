#include<stdlib.h>
#include<stdio.h>
#include<stdint.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        
        for(uint32_t i = 0; i < 32; i++){
            ret = (ret << 1) | (n & 1);
            n = n >> 1;
            ret = ret << 1;
        }
        
        return ret;
    }
};

int main(void){

    Solution sl;

    sl.reverseBits(3221225471);

    return true;
}
