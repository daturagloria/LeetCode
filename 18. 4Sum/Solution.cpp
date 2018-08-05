class Solution
{
  public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> ans;
        int len = nums.size();
        if (len < 4)
            return ans;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < len - 3; i++)
        {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target)
                break;
            if (nums[i] + nums[len - 3] + nums[len - 2] + nums[len - 1] < target)
                continue;
            for (int j = i + 1; j < len - 2; j++)
            {
                int k = j + 1, l = len - 1;
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target)
                    break;
                if (nums[i] + nums[j] + nums[len - 2] + nums[len - 1] < target)
                    continue;
                while (k < l)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                        k++;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                        l--;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                    else if (sum < target)
                    {
                        k++;
                        while (k < l && nums[k] == nums[k - 1])
                            k++;
                    }
                    else
                    {
                        l--;
                        while (k < l && nums[l] == nums[l + 1])
                            l--;
                    }
                }
            }
        }
        return ans;
    }
};