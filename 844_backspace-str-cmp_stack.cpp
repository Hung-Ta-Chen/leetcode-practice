class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> s1, s2;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '#'){
                if(!s1.empty()) s1.pop();
            }
            else s1.push(s[i]);
        }
        for(int i = 0; i < t.size(); i++){
            if(t[i] == '#'){
                if(!s2.empty()) s2.pop();
            }
            else s2.push(t[i]);
        }
        if(s1.size() != s2.size()) return false;
        while(!s1.empty()){
            char ch_1 = s1.top();
            char ch_2 = s2.top();
            if(ch_1 != ch_2) return false;
            s1.pop();
            s2.pop();
        }
        return true;
    }
};
