class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        nums = nums1 + nums2
        nums.sort()
        nums_left = nums[0:len(nums)/2]
        nums_right = nums[len(nums_left):len(nums)]

        if len(nums_right) == len(nums_left):
            return (float(max(nums_left)) + float(min(nums_right))) / 2
        else:
            return float(min(nums_right))
