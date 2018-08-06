class Solution
{
  public:
    bool isValid(string s)
    {
        vector<char> stack;
        for (string::iterator i = s.begin(); i != s.end(); i++)
        {
            if (*i == '{' || *i == '[' || *i == '(')
                stack.push_back(*i);
            else
            {
                if (stack.empty())
                    return false;
                char c = stack[stack.size() - 1];
                if ((c == '(' && *i == ')') || (c == '[' && *i == ']') || (c == '{' && *i == '}'))
                    stack.pop_back();
                else
                    return false;
            }
        }
        return stack.empty() ? true : false;
    }
};