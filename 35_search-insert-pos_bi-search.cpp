class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {       
        if (target <= nums[0]) return 0;
        if (target > nums[nums.size()-1]) return nums.size();
        
        int head = 0;
        int tail = nums.size() - 1;
        int m = head + (tail - head + 1) / 2;
        
        while(target <= nums[m-1] || target > nums[m]){  // Binary search
            if (target <= nums[m-1])
                tail = m - 1;
            else
                head = m;
            
            m = head + (tail - head + 1) / 2;             
        }
        return m;
    }
};
