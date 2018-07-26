class Solution
{
  public:
    int romanToInt(string s)
    {
        unordered_map<string, int> data = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};
        int ans = 0;
        int i = 0;
        while (i < s.size())
        {
            string search;
            if (i + 1 < s.size() && data.find(s.substr(i, 2)) != data.end())
            {
                ans += data.find(s.substr(i, 2))->second;
                i += 2;
            }
            else
            {
                ans += data.find(s.substr(i, 1))->second;
                i++;
            }
        }
        return ans;
    }
};