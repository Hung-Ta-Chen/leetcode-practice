/*
To see if a substring (index from i to j) is palindromic,
we check if the substring (index from i+1 to j-1) is palindromic and if s[i]==s[j]
(base case is i == j and j = i + 1)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1) return s;
        vector<vector<bool>> is_palindrome(s.size(), vector<bool>(s.size(), false));
        // We have to start from the last row 
        // because we always need the value of lower left corner to determine one value in memo
        int longest = 1, start = s.size()-1;
        for(int i = s.size()-1; i >= 0; i--){
            for(int j = i; j < s.size(); j++){
                // If (i == j) or (j = i+1), we only have to check if s[i] equals s[j] or not
                is_palindrome[i][j] = (j - i < 2)?s[i] == s[j]:(s[i] == s[j]) && is_palindrome[i+1][j-1];
                if(is_palindrome[i][j] && j - i + 1 > longest){
                    longest = j - i + 1;
                    start = i;
                }
            }
        }        
        return s.substr(start, longest);
    }
};
