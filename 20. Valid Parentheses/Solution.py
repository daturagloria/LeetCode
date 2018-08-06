class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        for i in s:
            if i in ['{', '(', "["]:
                stack.append(i)
            else:
                if not stack:
                    return False
                c = stack[-1]
                if (c == '(' and i == ')') or (c == '['
                                               and i == ']') or (c == '{'
                                                                 and i == '}'):
                    stack.pop()
                else:
                    return False
        return True if not stack else False