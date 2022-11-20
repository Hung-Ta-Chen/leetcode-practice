class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int idx = 0;
        int left_sum = 0;
        int right_sum = 0;  
        for(int i = 1; i < nums.size(); i++){
            right_sum += nums[i];
        }
        
        /*
        We start from index 0.
        If the current index is not pivot, we go to the next index
        and update left_sum and right_sum for next comparison.        
        We can update lest & right sum by simply add and substract a number respectively.
        
        |@|@| |@|@|@|   (idx: 2)
        |@|@|@| |@|@|   (idx: 3  => left+nums[2], right-nums[3])
        */
        while(left_sum != right_sum && idx != nums.size()-1){
            idx++;
            left_sum += nums[idx-1];
            right_sum -= nums[idx];
        }
        
        return (left_sum == right_sum)?idx:-1;
    }
};
