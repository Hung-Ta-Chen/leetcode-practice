class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size() == 0) return ans;
        map<char, pair<int, int>> num2alpha;
        num2alpha['2'] = pair<int, int>(0, 2);
        num2alpha['3'] = pair<int, int>(3, 5);
        num2alpha['4'] = pair<int, int>(6, 8);
        num2alpha['5'] = pair<int, int>(9, 11);
        num2alpha['6'] = pair<int, int>(12, 14);
        num2alpha['7'] = pair<int, int>(15, 18);
        num2alpha['8'] = pair<int, int>(19, 21);
        num2alpha['9'] = pair<int, int>(22, 25);
        
        string c;        
        comb(digits, 0, num2alpha, ans, c);
        return ans;
    }
    
    void comb(string& digits, int idx, map<char, pair<int, int>>& table, vector<string>& ans, string& c){
        pair<int, int> p = table[digits[idx]];
        if(idx == digits.size()-1){
            for(int i = p.first; i <= p.second; i++){
                c.push_back('a'+i);
                ans.push_back(c);
                c.pop_back();
            }
        }
        else{
            for(int i = p.first; i <= p.second; i++){
                c.push_back('a'+i);
                comb(digits, idx+1, table, ans, c);
                c.pop_back();
            }     
        }
    }
};
