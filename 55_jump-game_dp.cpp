/*
We start from the right of the array,
and use a memo (bottom-up) to see if a certain position can reach the last position.
*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return true;
        vector<bool> dp(n, false);
        dp[n-1] = true;
        for(int i = n-2; i >= 0; i--){
            int far = min(nums[i], n-1-i); 
            for(int j = 0; j <= far; j++){
                if(dp[i+j]){
                    dp[i] = true;
                    break;
                } 
            }
        }
        return dp[0];
    }
};
