class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = maxSubarray(nums, 0, nums.size()-1);
        return maxSub;
    }
    
    int maxSubarray(vector<int> &nums, int start, int end){
        if(end - start == 0) return nums[start];  // Base case
        else{
            // Recursive case
            int m = (start + end) / 2;  
            int l_max = maxSubarray(nums, start, m);  // Left half max
            int r_max = maxSubarray(nums, m+1, end);  // Right half max
            int m_max = maxMidSubarray(nums, start, m , end);  // Across middle max
            
            // Find the largest one
            if ((l_max) >= (r_max) && (l_max) >= (m_max)) return l_max;
            else if ((r_max) >= (l_max) && (r_max) >= (m_max)) return r_max;
            else return m_max;   
        }
    }
    
    int maxMidSubarray(vector<int> &nums, int start, int mid, int end){
        int left_max = INT_MIN;
        int sum = 0;
        int left_bound = -1;
        
        for(int i = mid; i >= start; i--){
            sum += nums[i];
            if(sum > left_max){
                left_max = sum;
                left_bound = i;
            }
        }
               
        int right_max = INT_MIN;
        sum = 0;
        int right_bound = -1;
        
        for(int i = mid+1; i <= end; i++){
            sum += nums[i];
            if(sum > right_max){
                right_max = sum;
                right_bound = i;
            }
        }
        return left_max+right_max;
    }
};
