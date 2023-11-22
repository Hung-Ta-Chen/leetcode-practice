class Solution:
    def isMatch(self, s: str, p: str) -> bool:
        dp = [[False] * (len(p)+1) for i in range(len(s)+1)]
        dp[0][0] = True

        for i in range(1, len(s)+1):
            dp[i][0] = False
        
        for j in range(2, len(p)+1):
            if p[j-1] == '*':
                dp[0][j] = dp[0][j-2]

        for i in range(1, len(s)+1):
            for j in range(1, len(p)+1):
                if p[j-1] == s[i-1] or p[j-1] == ".":
                    dp[i][j] = dp[i-1][j-1]
                elif p[j-1] == "*":
                    # We have two possibilities here, any of them works
                    # 1. '*' indicates 0 -> the char before '*' can be ignored.
                    # 2. '*' indicates >= 1 -> if the new char of s can matched 
                    # with the char before '*', we check if previous s can also
                    # match with p so that the new char is an extension of it.
                    dp[i][j] = dp[i][j-2] or (dp[i-1][j] if (p[j-2] == s[i-1] or p[j-2] == '.') else False)
        
        return dp[len(s)][len(p)]
