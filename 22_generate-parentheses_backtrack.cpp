/*
Two things you have to maintain when generating parenthesis:
1. # of left parenthesis <= n
2. # of right parenthesis <= # of left parenthesis
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string combo;
        backtrack(ans, combo, n, 0, 0);
        return ans;
    }
    void backtrack(vector<string>& ans, string& combo, int n, int l_num, int r_num){
        if(combo.size() == 2*n){
            ans.push_back(combo);
            return;
        }
        if(l_num < n){  // Can put more '('
            combo.push_back('(');
            backtrack(ans, combo, n, l_num+1, r_num);
            combo.pop_back();
        }
        if(r_num < l_num){  // Can put more ')'
            combo.push_back(')');
            backtrack(ans, combo, n, l_num, r_num+1);
            combo.pop_back();
        }
    }
};
