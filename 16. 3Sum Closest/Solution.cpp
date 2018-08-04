class Solution
{
  public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        int ans = nums[0] + nums[1] + nums[2];
        int close = abs(ans - target);
        sort(nums.begin(), nums.end());
        int i, j, k;
        int sum;
        for (i = 0; i < nums.size() - 2; i++)
        {
            j = i + 1;
            k = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > target)
            {
                sum = nums[i] + nums[i + 1] + nums[i + 2];
                return abs(sum - target) < close ? sum : ans;
            }
            if (nums[i] + nums[k - 1] + nums[k] < target)
            {
                sum = nums[i] + nums[k - 1] + nums[k];
                if (abs(sum - target) < close)
                {
                    close = abs(sum - target);
                    ans = sum;
                }
                continue;
            }
            while (j < k)
            {
                sum = nums[i] + nums[j] + nums[k];
                if (abs(sum - target) == 0)
                    return sum;
                else if (abs(sum - target) < close)
                {
                    close = abs(sum - target);
                    ans = sum;
                }
                if (sum < target)
                {
                    j++;
                    while (j < k and nums[j] == nums[j - 1])
                        j++;
                }
                else
                {
                    k--;
                    while (j < k and nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};