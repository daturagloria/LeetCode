class Solution:
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend == 0:
            return 0
        if dividend == -2**31 and divisor == -1:
            return 2**31 - 1
        positivie = (dividend > 0 and divisor > 0) or (dividend < 0
                                                       and divisor < 0)
        a = abs(dividend)
        b = abs(divisor)
        ans = 0
        while a >= b:
            shift = 0
            while a >= (b << shift):
                shift += 1
            a -= b << (shift - 1)
            ans += 1 << (shift - 1)
        return ans if positivie else -ans