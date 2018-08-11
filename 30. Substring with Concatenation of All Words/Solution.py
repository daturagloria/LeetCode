from collections import defaultdict


class Solution:
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        res = []
        s_len = len(s)
        words_len = len(words)
        if words_len == 0 or s_len < words_len * len(words[0]):
            return res
        word_len = len(words[0])
        total_len = word_len * words_len
        map_dict = defaultdict(int)
        cur_dict = defaultdict(int)
        for word in words:
            map_dict[word] = 1

        for start in range(0, s_len - total_len + 1):
            end = start
            while end < start + total_len:
                substr = s[end:end + word_len]
                cur_dict[substr] += 1
                if cur_dict[substr] > map_dict[substr]:
                    break
                end += word_len
            if end == start + total_len:
                res.append(start)
            cur_dict.clear()
        return res