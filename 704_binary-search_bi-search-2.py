class Solution:
    def search(self, nums: List[int], target: int) -> int:
        # high has to be len(nums) cuz the highest index that can be inserted is len(nums) 
        low = 0; high = len(nums)  
        # We find the rightmost position to insert the target
        while low < high:
            mid = (low + high) // 2
            if nums[mid] <= target:
                low = mid + 1
            else:
                # When nums[mid] is smaller than target, the highest possible index to insert is still mid
                high = mid
        if low != 0 and nums[low-1] == target: return low-1
        return -1
