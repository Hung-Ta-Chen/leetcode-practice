/*
Suppose s = [...]23
case 1 (single char): # of decoding ([...]23) = # of decoding ([...]2) since 3 can be decoded by itself
case 2 (double char): # of decoding ([...]23) = # of decoding ([...]) since 23 can also be decoded together
=> # of decoding ([...]23) is the sum of above two cases
*/
class Solution {
public:
    int numDecodings(string s) {
        vector<int> memo(s.size()+1, 0);
        memo[0] = 1;
        memo[1] = ('1' <= s[0] && s[0] <= '9')?1:0;
        for(int i = 2; i <= s.size(); i++){
                // single-char decoding
                if('1' <= s[i-1] && s[i-1] <= '9') memo[i] += memo[i-1];
                // double-char decoding
                if(s[i-2] == '1' && '0' <= s[i-1] && s[i-1] <= '9') memo[i] += memo[i-2];
                else if(s[i-2] == '2' && '0' <= s[i-1] && s[i-1] <= '6') memo[i] += memo[i-2];
        }
        return memo[s.size()];
    }
};
