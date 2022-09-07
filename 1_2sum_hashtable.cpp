class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;
        vector<int> ans;
        
        for(int i = 0; i < nums.size(); i++){
            if (table.find(target - nums[i]) == table.end())   // map.find(key) == map.end() if key not found
                table.insert(pair<int, int>(nums[i], i));    // if the complement number is not in hash table yet, insert it into the table
            else{ 
                // if find the complement, return the indices
                ans.push_back(table[target - nums[i]]);
                ans.push_back(i);
                return ans;
            }
        }
        return ans;
    }
};
