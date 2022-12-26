class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int low, high, mid;
        vector<int> ans(2, -1);
        // find start
        low = 0, high = nums.size()-1;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] < target) low = mid + 1;
            else if(nums[mid] > target) high = mid - 1;
            else{
                if(mid == 0 || nums[mid-1] != target){
                    ans[0] = mid;
                    break;
                }
                else high = mid - 1;
            }
        }       
        // find end
        low = 0, high = nums.size()-1;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] > target) high = mid - 1;
            else if(nums[mid] < target)low = mid + 1;
            else{
                if(mid == nums.size()-1 || nums[mid+1] != target){
                    ans[1] = mid;
                    break;
                } 
                else low = mid + 1;
            }
        }
        return ans;
    }
};
