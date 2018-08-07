class Solution
{
  public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ans;
        backtrack(ans, n);
        return ans;
    }
    void backtrack(vector<string> &ans, int n, string S = "", int left = 0, int right = 0)
    {
        if (S.size() == 2 * n)
        {
            ans.push_back(S);
            return;
        }
        if (left < n)
            backtrack(ans, n, S + "(", left + 1, right);
        if (right < left)
            backtrack(ans, n, S + ")", left, right + 1);
    }
};