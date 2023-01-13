'''
We use the sum of all elements int 'num'
the compare the value of left sum and the sum of the rest (all_sum - left_sum - nums[i])
'''
class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        all_sum = sum(nums)
        left_sum = 0
        for i in range(len(nums)):
            if(left_sum == all_sum - left_sum - nums[i]):
                return i
            left_sum += nums[i]
        return -1
