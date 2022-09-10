class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;       
        sort(nums.begin(), nums.end());
        
        int sum;
        int n = nums.size();
        // i, j two ptrs both come from front so that we can go from small to large
        // we can skip a lot of checking precedure in this way
        for(int i = 0; i <= n - 4; i++){
            if(i > 0 && nums[i] == nums[i-1])   
                continue;   // Avoid repetition
            
            // (Should have overflow handling here)
            // If the smallest sum for current i is still larger than target
            // there's no need to check other sum(even larger)
            // The reason of break instead of continue is that following i(s) are even larger
            sum = nums[i]+nums[i+1]+nums[i+2]+nums[i+3];
            if(sum > target) break;
            
            // (Should have overflow handling here)
            // If the largest sum for current i is still smaller than target
            // there's no need to check other sum(even smaller), just skip to next i
            sum = nums[i]+nums[n-3]+nums[n-2]+nums[n-1];
            if(sum < target) continue;
            
            for(int j = i+1; j <= n - 3; j++){
                if(j > i+1 && nums[j] == nums[j-1])   
                    continue;    // Avoid repetition
                
                // (Should have overflow handling here)
                // If the smallest sum for current j is still larger than target
                // there's no need to check other sum(even larger)
                // The reason of break instead of continue is that following j(s) are even larger
                sum = nums[i]+nums[j]+nums[j+1]+nums[j+2];
                if(sum > target) break;
                
                // (Should have overflow handling here)
                // If the largest sum for current j is still smaller than target
                // there's no need to check other sum(even smaller), just skip to next j
                sum = nums[i]+nums[j]+nums[n-2]+nums[n-1]
                if(sum < target) continue;
                
                // 2-ptr alg
                int ptr1 = j+1, ptr2 = n-1;
                while(ptr2 > ptr1){
                    if(ptr1 > j+1 && nums[ptr1] == nums[ptr1-1]){
                        ptr1++;
                        continue;
                    }
                        
                    if(ptr2 < n-1 && nums[ptr2] == nums[ptr2+1]){
                        ptr2--;
                        continue;
                    }
                    //cout << i<<" "<<j<<" "<<ptr1<<" "<<ptr2<<endl;
                    sum = nums[i]+nums[j]+nums[ptr1]+nums[ptr2];
                    if(sum < target){
                        ptr1++;
                    }
                    else if(sum > target){
                        ptr2--;
                    }
                    else{
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[ptr1]);
                        temp.push_back(nums[ptr2]);
                        result.push_back(temp);
                        ptr2--;
                        ptr1++;
                    }
                }
            }
        }       
        return result;
    }
};

/* Overflow handling part looks like this
int64_t sum_long = (int64_t)nums[i]+(int64_t)nums[i+1]+(int64_t)nums[i+2]+(int64_t)nums[i+3];     
if(sum_long > (int64_t)INT_MAX) break;
else if(sum_long < (int64_t)INT_MIN) sum = (int)INT_MIN;
else sum = (int)sum_long;  // sum won't overflow     
*/