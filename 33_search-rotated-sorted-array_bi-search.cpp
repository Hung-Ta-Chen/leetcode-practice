/*
case 1: no rotation
[(min)         (mid)               ]

case 2: rotation at left
[      ||(min)   (mid)             ]

case 3: rotation at right
[            (mid)    ||(min)      ]

*/
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1, mid;
        
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == target)
                return mid;
            
            // Rotated at right side (low can be the same as mid)
            if(nums[low] <= nums[mid]){
                // if target falls between low and mid
                if(nums[mid] > target && nums[low] <= target){
                    high = mid - 1;
                }
                else
                    low = mid + 1;
            }
            // Rotated at left side
            else if(nums[high] > nums[mid]){
                // if target falls between mid and high
                if(nums[mid] < target && nums[high] >= target){
                    low = mid + 1;
                }
                else
                    high = mid - 1;
            }
            // No rotation
            else{
                if(nums[mid] > target)
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }
        return -1;
    }
};
