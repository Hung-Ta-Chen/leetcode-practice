class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // We only have to put all k unique values in hte first k elements
        int unique = 1;  // "unique" keeps track of num of unique values found
        for(int i = 1; i < nums.size(); i++)
            if(nums[i] != nums[i-1]) nums[unique++] = nums[i];
        return unique;
    }
};
