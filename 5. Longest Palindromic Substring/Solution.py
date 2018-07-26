class Solution:
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        start, end = 0, 0
        for i in range(len(s)):
            len1 = self.expandAroundCenter(s, i, i)
            len2 = self.expandAroundCenter(s, i, i + 1)
            len_max = max(len1, len2)
            if len_max > (end - start):
                start = i - (len_max - 1) // 2
                end = i + len_max // 2 + 1
        return s[start: end]

    def expandAroundCenter(self, s, left, right):
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1
        return right - left - 1