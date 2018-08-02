class Solution:
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if not strs:
            return ""
        minlen = len(strs[0])
        for i in range(1, len(strs)):
            minlen = len(strs[i]) if len(strs[i]) < minlen else minlen
        if minlen == 0:
            return ""
        ans = ""
        for i in range(minlen):
            for j in range(len(strs) - 1):
                if strs[j][i] != strs[j + 1][i]:
                    return ans
            ans += strs[0][i]
        return ans
