#include <string>
#include <vector>
#include <unordered_map>
#include <iterator>
#include <iostream>
using namespace std;
class Solution
{
  public:
    vector<string> letterCombinations(string digits)
    {
        unordered_map<char, string> d = {{'2', "abc"},
                                         {'3', "def"},
                                         {'4', "ghi"},
                                         {'5', "jkl"},
                                         {'6', "mno"},
                                         {'7', "pqrs"},
                                         {'8', "tuv"},
                                         {'9', "wxyz"}};
        vector<string> ans;
        int len = digits.size();
        if (len == 0)
            return ans;
        else if (len == 1)
        {
            string str = d.find(digits[0])->second;
            for (int i = 0; i < str.size(); i++)
            {
                ans.push_back(str.substr(i, 1));
            }
        }
        else
        {
            vector<string> result = letterCombinations(digits.substr(0, len - 1));
            for (int i = 0; i < result.size(); i++)
                for (int j = 0; j < d.find(digits[len - 1])->second.size(); j++)
                    ans.push_back(result[i] + d.find(digits[len - 1])->second.substr(j, 1));
        }
        return ans;
    }
};