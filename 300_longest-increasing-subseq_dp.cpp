/*
We use a memo to store the longest increasing substring that "ends at pos i"
In this way, we can we get a new increasing substring when adding a new element
if the newly added element is larger than the element at index i.
*/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo(nums.size(), 1);
        for(int i = 1; i < nums.size(); i++){ 
            for(int j = 0; j < i; j++){ // Iterate through all the elements before ith element
                if(nums[j] < nums[i]){
                    memo[i] = max(memo[i], memo[j]+1);
                }
            }
        }
        int longest = 1;
        for(int i = 0; i < nums.size(); i++){
            if(memo[i] > longest) longest = memo[i];
        }
        return longest;
    }
};
