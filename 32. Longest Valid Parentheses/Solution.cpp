class Solution
{
  public:
    int longestValidParentheses(string s)
    {
        vector<int> stack1;
        vector<char> stack2;
        vector<bool> list;
        for (int i = 0; i < s.size(); i++)
            list.push_back(false);
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                stack1.push_back(i);
                stack2.push_back('(');
            }
            else
            {
                if (stack1.empty())
                    continue;
                int top1 = stack1.back();
                char top2 = stack2.back();
                stack1.pop_back();
                stack2.pop_back();
                if (top2 == '(')
                {
                    list[i] = true;
                    list[top1] = true;
                }
            }
        }
        int max_len = 0, cur_len = 0;
        for (int i = 0; i < list.size(); i++)
        {
            if (list[i])
                cur_len++;
            else
            {
                if (cur_len > max_len)
                    max_len = cur_len;
                cur_len = 0;
            }
        }
        if (cur_len > max_len)
            max_len = cur_len;
        return max_len;
    }
};
