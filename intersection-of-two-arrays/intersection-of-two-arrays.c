#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#define nSize 4

void sort(int* num, int left, int right){
    if(right <= left)
        return;
    
    int start = left;
    int end = right;
    int med = num[start + (end - start) / 2];
    

    while(end >= start){
        while(med > num[start]) start++;
        while(med < num[end]) end--;
        
        if(end >= start){
            int tmp = num[end];
            num[end] = num[start];
            num[start] = tmp;

            end--;
            start++;
        }
    }
    

    if(start < right)
        sort(num, start, right);

    if(left < end )
        sort(num, left, end);
}

int bSearch(int* nums, int left, int right, int target){
    while(right > left){
        int med = left + (right - left) / 2;
        
        if(nums[med] == target)
            return med;
        else if(nums[med] < target)
            left = med + 1;
        else
            right = med - 1;
    }
    
    return -1;
}


int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    sort(nums1, 0, nums1Size - 1);
    sort(nums2, 0, nums2Size - 1);

    *returnSize=0;
    int *res;
    res=(int *)calloc(nums1Size,sizeof(int *));

    int i = 0, j = 0; 
    while (i < nums1Size && j < nums2Size) 
    { 
        if (nums1[i] < nums2[j]) 
            i++; 
        else if (nums2[j] < nums1[i]) 
            j++; 
        else
        { 
            if(bSearch(res, 0, *returnSize, nums2[j]) < 0){
                res[*returnSize] = nums2[j];
                (*returnSize)++;
                printf("%d returnSize:%d\n",__LINE__, *returnSize);
            }
            j++; 
            i++;
        } 
    } 
    
    printf("returnSize:%d\n", *returnSize);
    for(int i = 0; i < *returnSize; i++){
        printf("%d, ", res[i]);
    }
    printf("\n");

    return res;
}


int main(void){
    int nums1[3] = {8, 0, 3};
    int nums2[2] = {0, 0};
    int ret = 0;
    
    intersection(nums1, 3, nums2, 2, &ret);

  //ort(nums1, 0, nSize - 1);

   /*for(int i = 0; i < nSize; i++){
        printf("%d, ", nums1[i]);
    }
    printf("\n");

    printf("%d \n", bSearch(nums1, 0, nSize - 1, 2));*/

    return 0;
}
