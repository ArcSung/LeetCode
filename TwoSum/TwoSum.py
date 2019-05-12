class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        
        for i, nums in enumerate(nums):
            if target - nums in dict:
                return (i, dict[target-nums])
            else:
                dict[nums] = i
