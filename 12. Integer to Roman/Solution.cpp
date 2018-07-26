class Solution
{
  public:
    string intToRoman(int num)
    {
        string ans;
        vector<int> size = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> data = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int i = 0;
        while (num != 0)
        {
            int x = num / size[i];
            num -= x * size[i];
            while (x--)
                ans += data[i];
            i++;
        }
        return ans;
    }
};