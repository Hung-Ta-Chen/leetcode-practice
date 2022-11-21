class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if (target <= nums[0]) return 0;
        if (target > nums[nums.size()-1]) return nums.size();
        
        int low = 0, high = nums.size()-1, mid;
        while(low <= high){
            mid = (low + high) / 2;   
            if(nums[mid] == target)
                // Find identical element, insert here
                return mid;
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid -1;           
        }
        // No idential element in the vector
        // low = high + 1
        // now low points to the element which is the successor of target
        return low;
    }
};
