class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, char> s2t;
        map<char, char> t2s;
        
        //Make sure s&t are -to-1 mapping with two hash tables
        for(int i = 0; i < s.size(); i++){
            if(s2t.find(s[i]) == s2t.end())
                s2t[s[i]] = t[i];
            else{
                if(s2t[s[i]] != t[i]) return false;
            }
            
            if(t2s.find(t[i]) == t2s.end())
                t2s[t[i]] = s[i];
            else{
                if(t2s[t[i]] != s[i]) return false;
            }
        }  
        return true;
    }
};
