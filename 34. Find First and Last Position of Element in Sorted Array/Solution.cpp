class Solution
{
  public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        int i = 0, j = nums.size() - 1;
        while (i <= j)
        {
            int mid = (i + j) >> 1;
            if (nums[mid] == target)
            {
                int left = mid, right = mid;
                while (left >= 0 && nums[left] == target)
                    left--;
                while (right <= nums.size() - 1 && nums[right] == target)
                    right++;
                return {left + 1, right - 1};
            }
            else if (nums[mid] < target)
            {
                i = mid + 1;
            }
            else
            {
                j = mid - 1;
            }
        }
        return {-1, -1};
    }
};