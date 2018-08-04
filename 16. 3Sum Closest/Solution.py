class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        ans = nums[0] + nums[1] + nums[2]
        close = abs(ans - target)
        for i in range(len(nums) - 2):
            j = i + 1
            k = len(nums) - 1
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            if nums[i] + nums[i + 1] + nums[i + 2] > target:
                sum = nums[i] + nums[i + 1] + nums[i + 2]
                return sum if abs(sum - target) < close else ans
            if nums[i] + nums[k - 1] + nums[k] < target:
                sum = nums[i] + nums[k - 1] + nums[k]
                if abs(sum - target) < close:
                    close = abs(sum - target)
                    ans = sum
                continue
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if abs(sum - target) == 0:
                    return sum
                elif abs(sum - target) < close:
                    close = abs(sum - target)
                    ans = sum
                if sum < target:
                    j += 1
                    while j < k and nums[j] == nums[j - 1]:
                        j += 1
                else:
                    k -= 1
                    while j < k and nums[k] == nums[k + 1]:
                        k -= 1
        return ans