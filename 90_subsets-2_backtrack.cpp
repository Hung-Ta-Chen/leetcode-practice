class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        for(int i = 0; i <= nums.size(); i++){
            backtrack(ans, subset, nums, i, 0);
        }
        return ans;
    }
    void backtrack(vector<vector<int>>& ans, vector<int>& subset, vector<int>& nums, int length, int start){
        if(subset.size() == length) ans.push_back(subset);
        else{
            for(int i = start; i < nums.size(); i++){
                if(i > start && nums[i] == nums[i-1]) continue;  // Skip all repeated elements
                subset.push_back(nums[i]);
                backtrack(ans, subset, nums, length, i+1);
                subset.pop_back();
            }
        }
    }
};
