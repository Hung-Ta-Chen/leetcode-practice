/*
We use a memo to record the # of arithmetic subarray ending at a given position

Let (a b c) be AS, if d and c also has the same difference.
then both (b c d) and (a b c d) are AS
So memo[i] = memo[i-1] + 1 when the condition is satisfied.
*/
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size() < 3) return 0;
        vector<int> memo(nums.size(), 0);
        int count = 0;
        for(int i = 2; i < nums.size(); i++){
            if(nums[i]-nums[i-1] == nums[i-1]-nums[i-2]) memo[i] = memo[i-1] + 1;
            count += memo[i];
        }
        return count;
    }
};
