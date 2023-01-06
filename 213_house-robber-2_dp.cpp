/*
Since the last element is adjacent to the first element,
there will be two candidates => (1): max value of 1st ~ (n-1)nd element    (2): max value of 2nd ~ (n)nd element
So we just use DP to find these two values respectively, and see which one is larger
*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int tot;
        vector<int> dp(nums.size(), 0);  // index i => tot amount for first i houses
        dp[0] = 0;
        // From house(1) to house(n-1)
        dp[1] = nums[0];
        for(int i = 2; i < nums.size(); i++){  
            dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
        }
        tot = dp[nums.size()-1];
        // From house(2) to house(n)
        dp[1] = nums[1];
        for(int i = 2; i < nums.size(); i++){  
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        tot = max(tot, dp[nums.size()-1]);
        return tot;
    }
};
