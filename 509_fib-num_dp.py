class Solution:
    def fib(self, n: int) -> int:
        if n == 0: return 0
        dp = [1] * n
        for i in range(2, n, 1):
            dp[i] = dp[i-2] + dp[i-1]
        return dp[n-1]
