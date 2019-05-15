class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        if len(set(s)) == 1: return s
        
        start, end, s_max = 0, 0, 0
        n = len(s)
        dp = [[0] * n for _ in range(n)]
        for i in range(n):
            for j in range(i):
                dp[j][i] = (s[i]==s[j]) & ((i - j < 2) | dp[j + 1][i - 1])
                if dp[j][i] and s_max < i - j + 1:
                    s_max = i - j + 1
                    start = j
                    end = i
            dp[i][i] = 1
        return s[start : end + 1]
