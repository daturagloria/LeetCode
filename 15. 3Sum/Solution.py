class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        ans = []
        if len(nums) < 3:
            return ans
        nums.sort()
        target = 0
        for i in range(len(nums) - 2):
            j = i + 1
            k = len(nums) - 1
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            if nums[i] + nums[i + 1] + nums[i + 2] > target:
                break
            if nums[i] + nums[k - 1] + nums[k] < target:
                continue
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == target:
                    ans.append([nums[i], nums[j], nums[k]])
                    j += 1
                    k -= 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
                elif sum < target:
                    j += 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                else:
                    k -= 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
        return ans
