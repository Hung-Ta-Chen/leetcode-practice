class Solution:
    def longestValidParentheses(self, s: str) -> int:
        dp = [0] * len(s)
        max_len = 0

        for i in range(1, len(s)):
            if s[i] == '(':
                continue
            if s[i] == ')':
                if s[i-1] == '(':
                    dp[i] = dp[i-2] + 2
                    max_len = max(max_len, dp[i])
                elif s[i-1] == ')' and i >= dp[i-1]+1 and s[i-dp[i-1]-1] == '(':
                    # ( |...)| )  => |...)|: longest valid ended at i-1
                    # don't forget to include the longest valid in front of that single '('
                    dp[i] = dp[i-dp[i-1]-2] + dp[i-1] + 2
                    max_len = max(max_len, dp[i])
        
        return max_len
