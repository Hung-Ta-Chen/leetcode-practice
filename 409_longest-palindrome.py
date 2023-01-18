class Solution:
    def longestPalindrome(self, s: str) -> int:
        longest = 0
        # Use collections.Counter to get the frequency of each character in s
        for count in collections.Counter(s).values():
            # Add the floor even number to the 'longest'
            longest += count // 2 * 2
            # If a unique character hasn't been included
            # we check if the current frequency is odd
            if longest % 2 == 0 and count % 2 == 1:
                longest += 1
        return longest
