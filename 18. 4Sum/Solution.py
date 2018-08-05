class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        ans = []
        if len(nums) < 4:
            return ans
        nums.sort()
        for i in range(len(nums) - 3):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            if sum(nums[i:i + 4]) > target:
                break
            if nums[i] + sum(nums[-3:]) < target:
                continue
            for j in range(i + 1, len(nums) - 2):
                k = j + 1
                l = len(nums) - 1
                if j > i + 1 and nums[j] == nums[j - 1]:
                    continue
                if nums[i] + sum(nums[j:j + 3]) > target:
                    break
                if nums[i] + nums[j] + sum(nums[-2:]) < target:
                    continue
                while k < l:
                    sum1 = nums[i] + nums[j] + nums[k] + nums[l]
                    if sum1 == target:
                        ans.append([nums[i], nums[j], nums[k], nums[l]])
                        k += 1
                        l -= 1
                        while k < l and nums[k] == nums[k - 1]:
                            k += 1
                        while k < l and nums[l] == nums[l + 1]:
                            l -= 1
                    elif sum1 < target:
                        k += 1
                        while k < l and nums[k] == nums[k - 1]:
                            k += 1
                    else:
                        l -= 1
                        while k < l and nums[l] == nums[l + 1]:
                            l -= 1
        return ans
