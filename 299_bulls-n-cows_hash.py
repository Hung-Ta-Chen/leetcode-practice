class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bull = 0; cow = 0
        # secret_freq = collections.Counter(secret)   
        secret_freq = collections.defaultdict(int)
        for ch in secret:
            secret_freq[ch] += 1
        for i, ch in enumerate(guess):
            if ch == secret[i]:
                bull += 1
                # If all freq is used, we moved on from cows to bulls
                if secret_freq[ch] == 0:
                    cow -= 1
                else:
                    secret_freq[ch] -= 1
            else:
                if secret_freq[ch] > 0:
                    cow += 1
                    secret_freq[ch] -= 1        
        return f'{bull}A{cow}B'
