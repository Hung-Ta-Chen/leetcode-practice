class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        ans = []
        self.perm(ans, [], nums)      
        return ans
        
    def perm(self, ans: List[List[int]], pre: List[int], rest: List[int]):
        if len(rest) == 1:  // Base case: only one remaining number
            ans.append(pre+rest)
        else:
            // Exhaust every combination
            for i in range(len(rest)):
                new_pre = pre + rest[i:i+1]
                if i == 0:
                    new_rest = rest[1:]
                elif i == len(rest)-1:
                    new_rest = rest[:len(rest)-1]
                else:
                    new_rest = rest[:i] + rest[i+1:]
                self.perm(ans, new_pre, new_rest)      
