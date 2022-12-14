/*
We can also start from 0 houses (dp[0]=0) for better generalization

####################################################################################
int rob(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];
    vector<int> dp(nums.size()+1, 0);  // index i => tot amount for first i houses
    dp[0] = 0;
    dp[1] = nums[0];
    for(int i = 2; i <= nums.size(); i++){
        dp[i] = max(dp[i-2]+nums[i-1], dp[i-1]);
    }
    return dp[nums.size()];
}
####################################################################################

*/
class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp(nums.size(), 0);  // index i of dp => including house 0 to i
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i < nums.size(); i++){
            dp[i] = max(dp[i-2]+nums[i], dp[i-1]);
        }
        return dp[nums.size()-1];
    }
};
