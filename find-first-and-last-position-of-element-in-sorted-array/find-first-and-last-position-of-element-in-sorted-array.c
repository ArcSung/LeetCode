#include<stdlib.h>
#include<stdio.h>


int find(int* nums, int numsSize, int target){
    int l = 0;
    int r = numsSize - 1;

    while(r >= l){
        int m = l + (r - l)/2;
        if(nums[m] < target)
            l = m+1;
        else
            r = m-1;
    }
    
    return l;
}



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize){
    int *res = malloc(2 * sizeof(int));
    *returnSize = 2;
    
    int start = find(nums, numsSize, target);
    int end = find(nums, numsSize, target + 1);
    
    if(start < numsSize && nums[start] == target){
        end -= 1;
    }
    else{
        start = -1;
        end = -1;
    }
        
    
    res[0] = start;
    res[1] = end;
    
    return res;
}

int main(){
    int nums[6] = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int re = 0;

    searchRange(nums, 6, target, &re);

    return 0;
}
