class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> dp(n, INT_MAX);
        dp[n-1] = 0;
        for(int i = n-2; i >= 0; i--){
            int far = min(nums[i], n-1-i); 
            for(int j = 1; j <= far; j++){
                if(dp[i+j] == INT_MAX) continue;   // if dp[i+j] = INT_MAX, you can't reach last index from here
                if(1 + dp[i+j] < dp[i]) dp[i] = 1 + dp[i+j];
            }
        }
        return dp[0];  //(dp[0]==INT_MAX)?0:dp[0]
    }
};
