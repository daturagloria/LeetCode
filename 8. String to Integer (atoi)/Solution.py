class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        if len(str) == 0:
            return 0
        str = str.lstrip()
        l1 = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
        l2 = l1 + ['+', '-']
        if len(str) == 0 or str[0] not in l2:
            return 0
        i = 0
        if str[i] == '-':
            sign = -1
            i += 1
        elif str[i] == '+':
            sign = 1
            i += 1
        else:
            sign = 1
        rev = 0
        INT_MAX = 2 ** 31 - 1
        INT_MIN = -2 ** 31
        while i < len(str) and str[i] in l1:
            digit = sign * (int(str[i]))
            if rev > INT_MAX // 10 or (rev == INT_MAX // 10 and digit > 7):
                return INT_MAX
            if rev < -(-INT_MIN // 10) or (rev == -(-INT_MIN // 10) and digit < -8):
                return INT_MIN
            rev = rev * 10 + digit
            i += 1
        return rev