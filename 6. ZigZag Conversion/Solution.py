class Solution:
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """
        if numRows == 1:
            return s
        n = len(s)
        ans = str()
        increase = 2 * numRows - 2
        for i in range(numRows):
            j = 0
            while i + j < n:
                ans += s[i + j]
                if i != 0 and i != numRows - 1 and j + increase - i < n:
                    ans += s[j + increase - i]
                j += increase
        return ans
