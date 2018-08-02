#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;
class Solution
{
  public:
    string longestCommonPrefix(vector<string> &strs)
    {
        if (!strs.size())
            return "";
        int minlen = strs[0].size();
        for (int i = 1; i < strs.size(); i++)
            minlen = strs[i].size() < minlen ? strs[i].size() : minlen;
        if (!minlen)
            return "";
        string ans("");
        for (int i = 0; i < minlen; i++)
        {
            for (int j = 0; j < strs.size() - 1; j++)
            {
                if (strs[j][i] != strs[j + 1][i])
                    return ans;
            }
            ans += strs[0][i];
        }
        return ans;
    }
};