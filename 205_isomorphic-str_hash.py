class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        s_to_t = {}
        t_to_s = {}
        for s_c, t_c in zip(s, t):
            if s_c not in s_to_t: s_to_t[s_c] = t_c
            else:
                if s_to_t.get(s_c) != t_c: return False
            if t_c not in t_to_s: t_to_s[t_c] = s_c
            else:
                if t_to_s.get(t_c) != s_c: return False
        return True
