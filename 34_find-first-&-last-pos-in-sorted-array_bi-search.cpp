class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> pos(2, -1);
        if(nums.size() == 0) return pos;
        
        int low = 0, high = nums.size()-1, mid;
        // Find the first position first
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == target){
                // If the match is at the head of array
                if(mid == 0){
                    pos[0] = mid;
                    break;
                }                    
                else{
                    // If the previous element of match doesn't match
                    if(nums[mid-1] != target){
                        pos[0] = mid;
                        break;
                    }            
                    else
                        high = mid - 1;
                }
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;       
        }
        
        // Find the last position
        low = 0, high = nums.size()-1;
        while(low <= high){
            mid = (low + high) / 2;
            if(nums[mid] == target){
                // If the match is at the tail of array
                if(mid == nums.size()-1){
                    pos[1] = mid;
                    break;
                }                   
                else{
                    // If the following element of match doesn't match
                    if(nums[mid+1] != target){
                        pos[1] = mid;
                        break;
                    }                  
                    else
                        low = mid + 1;
                }
            }
            else if(nums[mid] < target)
                low = mid + 1;
            else
                high = mid - 1;       
        }        
        return pos;
    }
};
