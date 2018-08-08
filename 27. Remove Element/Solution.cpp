class Solution
{
  public:
    int removeElement(vector<int> &nums, int val)
    {
        if (nums.size() < 1)
            return 0;
        int i, j;
        for (i = 0, j = 0; j < nums.size(); j++)
        {
            if (nums[j] != val)
                nums[i++] = nums[j];
        }
        return i;
    }
};