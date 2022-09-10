class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());
        
        int ptr1_out = 0, ptr2_out = nums.size() - 1;
        int ptr1_in, ptr2_in;
        
        // Use two extra pointers to try every possible combination
        // 2-pointer alg works on the range between them
        for(int ptr2_out = nums.size() - 1; ptr2_out >= 3; ptr2_out--){
            // If the number is the same as previous one, skip it
            if(ptr2_out < nums.size() - 1 && nums[ptr2_out] == nums[ptr2_out + 1])
                continue;

            for(int ptr1_out = 0; ptr1_out <= ptr2_out - 3; ptr1_out++){
                // If the number is the same as previous one, skip it
                if(ptr1_out > 0 && nums[ptr1_out] == nums[ptr1_out - 1])
                    continue;
                
                ptr1_in = ptr1_out + 1;
                ptr2_in = ptr2_out - 1;

                while(ptr2_in > ptr1_in){             
                    // If the number at ptr1_in and ptr2_in is the same as the previous number
                    // Skip it to avoid repetition
                    if(ptr1_in > ptr1_out + 1 && nums[ptr1_in] == nums[ptr1_in - 1]){
                        ptr1_in++;
                        continue;
                    }
                    if(ptr2_in < ptr2_out - 1 && nums[ptr2_in] == nums[ptr2_in + 1]){
                        ptr2_in--;
                        continue;
                    }
                    
                    // Avoid overflow when computing sum by using 64-bit integer
                    int64_t sum_long = (int64_t)nums[ptr1_in] + (int64_t)nums[ptr2_in] + (int64_t)nums[ptr1_out] + (int64_t)nums[ptr2_out];     
                    int sum;
                    
                    if(sum_long > (int64_t)INT_MAX){
                        ptr2_in--;
                        continue;
                    }
                    else if(sum_long < (int64_t)INT_MIN){
                        ptr1_in++;
                        continue;
                    }
                    else{
                        sum = (int)sum_long;  // sum won't overflow
                    }
                    
                    // Compare the sum with the target to adjust pointers
                    if(sum < target){
                        ptr1_in++;
                    }
                    else if(sum > target){
                        ptr2_in--;
                    }
                    else{
                        vector<int> temp;
                        temp.push_back(nums[ptr1_out]);
                        temp.push_back(nums[ptr1_in]);
                        temp.push_back(nums[ptr2_in]);
                        temp.push_back(nums[ptr2_out]);

                        result.push_back(temp);
                        ptr2_in--;
                    }    
                }
            }
        }
        return result;
    }
};