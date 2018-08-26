class Solution:
    def searchInsert(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        i = 0
        length = len(nums) - 1
        while i <= length and nums[i] < target:
            i += 1
        return i