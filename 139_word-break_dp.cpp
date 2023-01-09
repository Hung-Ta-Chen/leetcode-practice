/*
memo[i]: if subtr from 0 to i-1 can be segmented

We separate the string ( length = len, 0~(len-1) ) into two parts: prefix(0 ~ i-1) and suffix(i ~ len-1)
We check the memo to see if the prefix can be segmented into word in dict, 
then we check if the suffix is in the dictionary.

We increment the length from 1 to s.size() so that we can get memo[i] in every iteration,
since i is always smaller than len.

p.s (0 ~ -1) means empty string.
*/
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        set<string> hash(wordDict.begin(), wordDict.end());
        vector<bool> memo(s.size()+1, false);
        memo[0] = true;
        for(int len = 1; len <= s.size(); len++){
            for(int i = 0; i < len; i++){
                if(memo[i] && hash.find(s.substr(i, len-i)) != hash.end()){
                    memo[len] = true;
                    break;
                }
            }
        }
        return memo[s.size()];
    }
};
