class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int max_len = 0;
        int n = s.size();
        for (int i = 0, j = 0; j < n; j++) {
            if (map.find(s[j]) != map.end())
                i = map[s[j]] >= i ? map[s[j]] + 1 : i;
            max_len = max_len > j - i + 1 ? max_len : j - i + 1;
            map[s[j]] = j;
        }
        return max_len;
    }
};