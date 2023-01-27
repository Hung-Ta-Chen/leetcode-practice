/*
example: cost = [10, 15, 20]

0  1  2  3  4
            _
         _ |
      _ |
   _ |
_ |
f           c

  10  15 20    <- cost
  
To get to floor => 0 cost
To get to stair1 => 0 cost (cost 0 from floor + 1 step)
To get to stair2 => 0 cost (cost 0 from floor + 2 step)
*/
class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        dp = [0] * (len(cost)+2)
        for i in range(3, len(cost)+2, 1):
            dp[i] = min(dp[i-2] + cost[i-2-1], dp[i-1] + cost[i-1-1])
        return dp[-1]
