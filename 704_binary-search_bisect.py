class Solution:
    def search(self, nums: List[int], target: int) -> int:
        idx = bisect.bisect_left(nums, target)
        if idx == len(nums) or nums[idx] != target: return -1
        else: return idx
