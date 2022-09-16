class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        if(t.size() == 0) return false;
        if(s.size() > t.size()) return false;
        
        int idx_s = 0, idx_t = 0;
        
        //Iterate through the string t
        while(idx_t < t.size()){
            //If find a match to current char in string s, go to the next char in s
            if(t[idx_t++] == s[idx_s]) idx_s++;  
            if(idx_s >= s.size()) return true; //When all char in s are matched, return true
        }       
        return false;
    }
};