class Solution
{
  public:
    int divide(int dividend, int divisor)
    {
        if (dividend == 0)
            return 0;
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        bool positive = (dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0);
        int ans = 0;
        long a = abs((long)dividend);
        long b = abs((long)divisor);
        while (a >= b)
        {
            int shift = 0;
            while (a >= (b << shift))
            {
                shift++;
            }
            a -= b << (shift - 1);
            ans += 1 << (shift - 1);
        }
        return positive ? ans : -ans;
    }
};