class Solution:
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i < 0:
            self.reverse(nums, i)
        else:
            start = i
            i += 1
            pre = start
            while i < len(nums) and nums[start] < nums[i]:
                i += 1
                pre += 1
            temp = nums[start]
            nums[start] = nums[pre]
            nums[pre] = temp
            self.reverse(nums, start)

    def reverse(self, nums, start):
        if start < 0:
            nums.reverse()
        else:
            i, j = start + 1, len(nums) - 1
            while i < j:
                nums[i], nums[j] = nums[j], nums[i]
                i += 1
                j -= 1