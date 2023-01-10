/*
We use a table 'dp' to record the least # of coins needed for amount 0 to i.
To get the least # of coins needed for amount i, we just iterate through the 'coin' array,
and use the smallest dp[i-coins[j]]+1 as dp[i]
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < coins.size(); j++){
                if(i - coins[j] < 0) continue;  // i-coins[j] less than  0
                if(dp[i-coins[j]] == INT_MAX) continue;   // i-coins[j] cannot be made up by these coins
                dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        return (dp[amount] == INT_MAX)?-1:dp[amount];
    }
};
