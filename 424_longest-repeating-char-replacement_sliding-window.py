# We use sliding window to solve the problem. (use low & high 2 pointers, low: lowest pos of the window, high: highest pos of the window)
# In every iteration, we move 'high' toward the end by one element, and update the freq hashmap.
# If the tot # of chars other than highest freq char exceed k after moving 'high', 
# we move 'low' toward the end until it's valid again, and update the hashmap.

# p.s: we actually can just use the max freq by far instead of keep finding current max freq in every iteration
class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        low = 0; high = 0
        freq_map = collections.defaultdict(int)
        max_len = 0
        max_freq = 0
        while high < len(s):
            freq_map[s[high]] += 1
            max_freq = max(freq_map.values())
            while high-low+1-max_freq > k:
                freq_map[s[low]] -= 1
                low += 1
                max_freq = max(freq_map.values())
            max_len = max(max_len, high-low+1)
            high += 1
        return max_len
