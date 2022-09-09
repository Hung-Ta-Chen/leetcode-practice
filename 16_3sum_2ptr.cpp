class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());  // Sort the vector first
        
        int min_deficit = INT_MAX;
        int flag = 1; //(1: plus, -1: minus)

        // Use 2-ptr algorithm to find the closest sum to the target 
        int ptr1, ptr2;
        for(int i = 0; i < nums.size() - 2; i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            
            ptr1 = i + 1;
            ptr2 = nums.size() - 1;
            
            while(ptr1 != ptr2){
                if(ptr1 > i+1 && nums[ptr1] == nums[ptr1-1]){
                    ptr1++;
                    continue;
                }
                
                if(ptr2 < nums.size()-1 && nums[ptr2] == nums[ptr2+1]){
                    ptr2--;
                    continue;
                }
                
                int sum = nums[ptr1] + nums[ptr2] + nums[i];
                    
                if(sum < target){
                    if(abs(sum - target) < min_deficit){
                        min_deficit = abs(sum - target);
                        flag = -1;  // Set the deficit as negative
                    }
                    ptr1++;   
                }
                else if(sum > target){
                    if(abs(sum - target) < min_deficit){
                        min_deficit = abs(sum - target);
                        flag = 1;   // Set the deficit as positive
                    }     
                    ptr2--; 
                }
                else{
                    return target;
                }
            }    
        }    
        return target + flag * min_deficit;
    }
};