class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        for(int i = 0; i <= nums.size(); i++){
            backtrack(ans, subset, nums, i, 0);
        }
        return ans;
    }
    void backtrack(vector<vector<int>>&ans, vector<int>&subset, vector<int>& nums, int length, int start){
        if(subset.size() == length) ans.push_back(subset); // 長度到了 => save it into answer 
        else{
            for(int i = start; i < nums.size(); i++){
                subset.push_back(nums[i]);
                backtrack(ans, subset, nums, length, i+1);  // recursively select elements from those behind the current element
                subset.pop_back();
            }
        }
    }
};
