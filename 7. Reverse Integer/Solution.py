class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        rev = 0
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        while x != 0:
            if x > 0:
                pop = x % 10
                x //= 10
            else:
                pop = -(-x % 10)
                x = -(-x // 10)
            if rev > INT_MAX // 10 or (rev == INT_MAX // 10 and pop > 7):
                return 0
            if rev < -(-INT_MIN // 10) or (rev == INT_MIN // 10 and pop < -8):
                return 0
            rev = rev * 10 + pop
        return rev