class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        stack = []
        l = [False for _ in range(len(s))]
        for i in range(len(s)):
            if s[i] == '(':
                stack.append((i, '('))
            else:
                if not stack:
                    continue
                top = stack.pop()
                if top[1] == '(':
                    l[i] = True
                    l[top[0]] = True
        max_len = 0
        cur_len = 0
        for i in l:
            if i:
                cur_len += 1
            else:
                if cur_len > max_len:
                    max_len = cur_len
                cur_len = 0
        if cur_len > max_len:
            max_len = cur_len
        return max_len