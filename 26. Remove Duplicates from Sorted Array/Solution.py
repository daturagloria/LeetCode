class Solution:
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 2:
            return len(nums)
        i, j = 0, 1
        while j < len(nums):
            if nums[i] < nums[j]:
                i += 1
                nums[i] = nums[j]
            j += 1
        return i + 1