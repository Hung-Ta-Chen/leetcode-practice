//Sort是個好東西，可以多用
//比較元素相同但順序不同的兩strings => 先sort再比
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, int> table;
        vector<vector<string>> ans;
        
        int count = 0;  //Count the current number of anagram groups
        for(int i = 0; i < strs.size(); i++){
            string temp(strs[i]);
            sort(temp.begin(), temp.end());   //Sort the string for comparison
            
            if(table.find(temp) == table.end()){ //If no matching anagram group in the table
                table[temp] = count++;   //remember this anagram group
                vector<string> vec;      //Push the group into the ans
                vec.push_back(strs[i]);
                ans.push_back(vec);
            }           
            else{    //If matvhing group is found in the table
                ans[table[temp]].push_back(strs[i]);   //Push it in the corresponding vector in ans
            }
        }
        
        return ans;
    }
};