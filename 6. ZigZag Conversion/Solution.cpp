class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        string ans;
        int n = s.size();
        int increase = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; i + j < n; j += increase) {
                ans += s[i + j];
                if (i != 0 && i != numRows - 1 && j + increase - i < n)
                    ans += s[j + increase - i];
            }
        }
        return ans;
    }
};