class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        s = ''
        data = [
            "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV",
            "I"
        ]
        size = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
        for i in range(len(size)):
            x = num // size[i]
            num -= x * size[i]
            while x != 0:
                s += data[i]
                x -= 1
        return s
