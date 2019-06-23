#include<stdlib.h>
#include<stdio.h>
#include<vector>

using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        for(int i=0;i<matrix.size();i++)
        {
            int start=0,end=matrix[i].size()-1;
            if(!(matrix[i][0] <= target && matrix[i][end] >= target))
                continue;

            while(start<=end)
            {
                int mid=(start+end)/2;
                if(matrix[i][mid]==target)
                    return true;
                else if(matrix[i][mid]<target)
                    start=mid+1;
                else
                    end=mid-1;
            }
        }
        return false;
    }
};


int main(void){
    Solution sl;

    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};

    int ret = sl.searchMatrix(matrix, 3);

    printf("ret:%d\n", ret);

    return ret;
}
