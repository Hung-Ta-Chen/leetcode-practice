# This is the slower version
# We just set each character in the string as the one to keep
# and fine the max length

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        char_set = set(s)
        max_len = 0
        for ch in char_set:
            freq_map = collections.defaultdict(int)
            low, high = 0, 0
            while high < len(s):
                freq_map[s[high]] += 1
                while high-low+1-freq_map[ch] > k:
                    freq_map[s[low]] -= 1
                    low += 1
                max_len = max(max_len, high-low+1)
                high += 1
        return max_len
