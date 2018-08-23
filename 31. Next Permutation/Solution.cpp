class Solution
{
  public:
    void nextPermutation(vector<int> &nums)
    {
        int i = nums.size() - 2;
        while (i >= 0 && nums[i] >= nums[i + 1])
            i--;
        if (i < 0)
            reverse(nums, i);
        else
        {
            int start = i;
            int pre = start;
            i++;
            while (i < nums.size() && nums[start] < nums[i])
            {
                i++;
                pre++;
            }
            swap(nums[start], nums[pre]);
            reverse(nums, start);
        }
    }
    void reverse(vector<int> &nums, int start)
    {
        int i;
        int j = nums.size() - 1;
        if (start < 0)
            i = 0;
        else
            i = start + 1;
        while (i < j)
            swap(nums[i++], nums[j--]);
    }
};