class Solution {
public:
    int findMin(vector<int>& nums) {
        int low, high, mid;
        low = 0, high = nums.size()-1;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[low] <= nums[high]) // not rotated
                return nums[low];
            else{                       // rotated  
                if(mid != 0 && nums[mid] < nums[mid-1]) return nums[mid]; // if mid is the inflection point
                if(nums[low] > nums[mid]) high = mid - 1;
                else if(nums[low] <= nums[mid]) low = mid + 1;
            }
        }
        return -1;
    }
};
