class Solution
{
  public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int maxArea = 0;
        while (i < j)
        {
            if (min(height[i], height[j]) * (j - i) > maxArea)
                maxArea = min(height[i], height[j]) * (j - i);
            if (height[i] > height[j])
                j--;
            else
                i++;
        }
        return maxArea;
    }
};