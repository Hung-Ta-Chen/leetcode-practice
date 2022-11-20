class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        swap_two_elements(nums, 0, permutations);
        return permutations;
    }
    void swap_two_elements(vector<int>& nums, int low, vector<vector<int>>& perm){
        if(low == nums.size()-1)
            perm.push_back(nums);
        else{
            for(int i = low; i < nums.size(); i++){
                // Swap the lowest element and i-th element for further permutaton
                swap(nums[low], nums[i]);
                // Recursion (DFS)
                swap_two_elements(nums, low+1, perm);
                // Swap the swapped two elements back
                swap(nums[low], nums[i]); 
            }
        }
    }
};
