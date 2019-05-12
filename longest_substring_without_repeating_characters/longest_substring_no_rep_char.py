class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        max = 0
        dict = {}
        
        for i, s in enumerate(s):
            if s in dict:
                dict = {key:val for key, val in dict.items() if val >= dict[s]}

            dict[s] = i;
            max = len(dict) if max < len(dict) else max
        
                
        return max
