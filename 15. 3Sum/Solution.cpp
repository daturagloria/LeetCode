class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> ans;
        if (nums.size() < 3)
            return ans;
        sort(nums.begin(), nums.end());
        const int target = 0;
        int i, j, k;
        for (i = 0; i < nums.size() - 2; i++)
        {
            j = i + 1;
            k = nums.size() - 1;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] > target)
                break;
            if (nums[i] + nums[k - 1] + nums[k] < target)
                continue;
            while (j < k)
            {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
                else if (sum < target)
                {
                    j++;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;
                }
                else
                {
                    k--;
                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }
};