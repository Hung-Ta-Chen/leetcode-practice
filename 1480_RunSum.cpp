class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        if(nums.size() == 1) return nums;
        
        vector<int> runSum(nums.size(), 0);    
        runSum[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            runSum[i] = runSum[i-1] + nums[i];
        }        
        return runSum;
    }
};