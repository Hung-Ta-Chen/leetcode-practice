class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() == 1) return;
        // Find nonincreasing sequence from the tail
        int pivot, s;     
        for(pivot = nums.size()-2; pivot >= 0; pivot--){
            if(nums[pivot] < nums[pivot+1])
                break;
        }
        
        // if pivot is not found
        if(pivot < 0)
            reverse(nums.begin(), nums.end());
        // if pivot is found
        else{
            // find the successor of the pivot in hte nonincreasing seq
            for(s = nums.size()-1; s > pivot; s--){
                if(nums[s] > nums[pivot])
                    break;
            }
            swap(nums[pivot], nums[s]);
            // REverse the nonincreasing seq after the swap
            reverse(nums.begin()+pivot+1, nums.end());
        }
    }
};
