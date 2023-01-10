/*
Consider now we have word1 [.......at] (0 to i-1) and word2 [.........gc] (0 to j-1)
To find min distance of them, we have three candidates.
**ps. We can imagine those two prefic substrings both have been edited to the same string.
(1) (the min distance of [.......a] and [.........g]) + 1 (here we replace t in word1 with c or vice versa)
(The following two candidiates are similiar, we remove that newly added character in the string since those two substrings already been edited to the same.)
(2) (the min distance of [.......at] and [.........g]) + 1  (here we remove c in word1)
(3) (the min distance of [.......a] and [.........gc]) + 1  (here we remove t in word2)
*/
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1, vector(word2.size()+1, 0));
        for(int i = 0; i <= word1.size(); i++) dp[i][0] = i;
        for(int j = 0; j <= word2.size(); j++) dp[0][j] = j;
        for(int i = 1; i <= word1.size(); i++){
            for(int j = 1; j <= word2.size(); j++){
                if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
                else{
                    dp[i][j] = min(dp[i-1][j-1]+1, dp[i-1][j]+1);
                    dp[i][j] = min(dp[i][j], dp[i][j-1]+1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
