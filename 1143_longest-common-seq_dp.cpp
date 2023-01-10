/*
When the characters at the current position in the two input strings are not the same, 
adding the current character to the LCS would cause the sequence to no longer be a common subsequence, 
and we cannot use the current character to extend the LCS. In this case, 
the only option we have is to consider the subproblems that do not include the current character in either of the input strings.

Therefore, by taking the maximum of the two subproblems (X[0..i-2] & Y[0..j-1]) vs (X[0..i-1] & Y[0..j-2]), 
we are choosing the one that has the longer LCS and using that as the LCS for the current subproblem, 
regardless of whether the current characters are in the LCS or not, 
by doing this we'll be considering all possible combinations of LCSes and by that we're going to find the LCS of the complete string X and Y.
*/
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, 0));
        for(int i = 1; i <= text1.size(); i++){
            for(int j = 1; j <= text2.size(); j++){
                if(text1[i-1] == text2[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
                else dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        return dp[text1.size()][text2.size()];
    }
};
