class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string s("");
        
        // Compare the first string with the rest of strings char by char
        for(int i = 0; i < strs[0].length(); i++){
            bool flag = true;
            
            for(int j = 1; j < strs.size(); j++){
                if (strs[j][i] != strs[0][i]){
                    flag = false; // Difference deteced
                    break;
                }
            }
            
            if (flag) 
                s.append(string(1, strs[0][i]));
            else 
                break;
        }
        
        return s;
    }
};