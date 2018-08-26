class Solution
{
  public:
    int searchInsert(vector<int> &nums, int target)
    {
        int i = 0;
        int length = nums.size() - 1;
        while (i <= length && nums[i] < target)
            i++;
        return i;
    }
};