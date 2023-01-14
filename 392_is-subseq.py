class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        if len(s) > len(t): return False
        if len(s) == 0: return True
        s_ptr = 0
        for y_ptr in range(len(t)):
            if s[s_ptr] == t[y_ptr]: s_ptr += 1
            if s_ptr == len(s): return True
        return False
