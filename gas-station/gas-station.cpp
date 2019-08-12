
#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;

class Solution {
public:
   int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        if(!gas.size() || !cost.size())
            return 0;

        int m = gas.size();
        for(int i = 0; i < m; i++){
            int q = gas[i];
            int j = i + 1;
            for(; j <= i + m ; j++){
                q -= cost[(j - 1) % m];
                if(q < 0) break;
                q += gas[j % m];
            }

            if(q >= 0) return i;
        }


        return -1;   
    }
};


int main(void){
    Solution sl;
    vector<int> gas = {4,5,3,1,4};
    vector<int> cost = {5,4,3,4,2};
    int ret = sl.canCompleteCircuit(gas, cost);

    printf("ret :%d\n", ret);

    return 1;
}
