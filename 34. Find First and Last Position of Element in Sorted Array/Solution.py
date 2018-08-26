class Solution:
    def searchRange(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        i, j = 0, len(nums) - 1
        while i <= j:
            mid = (i + j) >> 1
            if nums[mid] == target:
                left, right = mid, mid
                while left >= 0 and nums[left] == target:
                    left -= 1
                while right <= len(nums) - 1 and nums[right] == target:
                    right += 1
                return [left + 1, right - 1]
            elif nums[mid] < target:
                i = mid + 1
            else:
                j = mid - 1
        return [-1, -1]