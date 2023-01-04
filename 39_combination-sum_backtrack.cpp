class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> combo;
        backtrack(candidates, target, ans, combo, 0);
        return ans;
    }
    void backtrack(vector<int>& cand, int target, vector<vector<int>>& ans, vector<int>& combo, int low){
        if(target == 0){
            ans.push_back(combo);
            return;
        }
        if(target < 0) return;
        for(int i = low; i < cand.size(); i++){
            combo.push_back(cand[i]);
            // We only choose from the elements whose index is <= current index (avoid duplication)
            backtrack(cand, target-cand[i], ans, combo, i); 
            combo.pop_back();
        }
    }
};
