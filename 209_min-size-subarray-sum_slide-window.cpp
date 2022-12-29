class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len = INT_MAX;
        int sum = 0;
        int left, right;
        for(left = 0, right = 0; right < nums.size(); right++){
            sum += nums[right];
            while(sum >= target && left < right){
                min_len = min(min_len, right - left + 1);
                sum -= nums[left++];
            }
            // If a single element is larger than the target when left equals right
            if(nums[right] >= target) min_len = min(min_len, 1);
        }
        return (min_len == INT_MAX)?0:min_len;
    }
};
