class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        if (x == 0)
            return true;
        vector<int> n;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            n.push_back(pop);
        }
        for (int i = 0, j = n.size() - 1; i <= j; i++, j--) {
            if (n[i] != n[j])
                return false;
        }
        return true;
    }
};