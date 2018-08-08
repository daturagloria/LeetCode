class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() < 2)
            return nums.size();
        int i, j;
        for (i = 0, j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] < nums[j])
            {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};