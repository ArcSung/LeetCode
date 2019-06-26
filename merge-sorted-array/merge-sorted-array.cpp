#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <vector> 
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {        
        int i1 = m-1, i2 = n-1, e1 = m + n - 1;

        while(i1 >= 0 && i2 >= 0){
            if(nums1[i1] > nums2[i2])
                nums1[e1--] = nums1[i1--];
            else
                nums1[e1--] = nums2[i2--];
        }

        while(i1>=0) nums1[e1--] = nums1[i1--];
        while(i2>=0) nums1[e1--] = nums2[i2--];
    }
};

int main(void){
	Solution sl;

    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

	sl.merge(nums1, 3, nums2, 3);

	return true;
}
