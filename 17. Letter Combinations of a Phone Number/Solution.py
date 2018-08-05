class Solution:
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        d = {
            "2": "abc",
            "3": "def",
            "4": "ghi",
            "5": "jkl",
            "6": "mno",
            "7": "pqrs",
            "8": "tuv",
            "9": "wxyz"
        }
        ans = []
        digits_len = len(digits)
        if digits_len == 0:
            return ans
        elif digits_len == 1:
            return list(d[digits[0]])
        else:
            result = self.letterCombinations(digits[:digits_len - 1])
            for i in d[digits[-1]]:
                for j in result:
                    ans.append(j + i)
        return ans
