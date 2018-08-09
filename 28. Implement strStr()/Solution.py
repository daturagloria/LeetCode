class Solution:
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        len1 = len(haystack)
        len2 = len(needle)
        if len2 == 0:
            return 0
        if len1 < len2:
            return -1
        for i in range(len1 - len2 + 1):
            j = 0
            while j < len2 and haystack[i + j] == needle[j]:
                j += 1
            if j == len2:
                return i
        return -1