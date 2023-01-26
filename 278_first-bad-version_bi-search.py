# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        low = 1; high = n
        while low < high:
            mid = (low + high) // 2
            if isBadVersion(mid):
                # Our candidate will still include mid
                high = mid
            else:
                # Our candidate won't include mid
                low = mid + 1
        return low
