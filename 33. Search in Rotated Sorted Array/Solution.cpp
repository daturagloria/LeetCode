class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        int length = nums.size();
        int left = 0, right = length - 1;
        int mid;
        while (left <= right)
        {
            mid = (left + right) >> 1;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < nums[right])
            {
                if (target <= nums[right] && target > nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
            else
            {
                if (target < nums[mid] && target >= nums[left])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
        }
        return -1;
    }
};