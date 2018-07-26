class Solution {
public:
    int myAtoi(string str) {
        int n = str.size();
        if (n == 0)
            return 0;
        int i = 0;
        while (str[i] == ' ' && i < n)
            i++;
        if (i == n || (str[i] != '-' && str[i] != '+'&& str[i] < '0' && str[i] > 9))
            return 0;
        int sign;
        if (str[i] == '-') {
            sign = -1;
            i++;
        }
        else if (str[i] == '+') {
            i++;
            sign = 1;
        }
        else {
            sign = 1;   
        }
        int rev = 0;
        while (str[i] >= '0' && str[i] <= '9') {
            int digit = sign * (0 + str[i++] - '0');
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7))
                return INT_MAX;
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8))
                return INT_MIN;
            rev = 10 * rev + digit;
        }
        return rev;
    }
};