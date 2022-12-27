class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
    int helper(vector<int>& nums, int low, int high){
        if(low == high) return low;
        int mid = (low + high) / 2;
        int left = helper(nums, low, mid);
        int right = helper(nums, mid+1, high);
        return (nums[left] > nums[right])?left:right;
    }
};
