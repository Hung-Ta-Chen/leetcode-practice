class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            if (table.find(target - nums[i]) == table.end())
                table.insert(pair<int, int>(nums[i], i));
            else{
                ans.push_back(table[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};