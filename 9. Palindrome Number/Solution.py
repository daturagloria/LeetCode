class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        if x == 0:
            return True
        l = []
        while x != 0:
            pop = x % 10
            x //= 10
            l.append(pop)
        i = 0
        j = len(l) - 1
        while i <= j:
            if l[i] != l[j]:
                return False
            i += 1
            j -= 1
        return True
