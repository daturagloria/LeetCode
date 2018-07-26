class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        d = {}
        max_len = 0
        i = 0
        for j in range(len(s)):
            if s[j] in d:
                i = d[s[j]] + 1 if d[s[j]] >= i else i
            max_len = max(j - i + 1, max_len)
            d[s[j]] = j
        return max_len
