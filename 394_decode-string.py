class Solution:
    def decodeString(self, s: str) -> str:
        count_stack = []
        ch_stack = []
        i = 0
        while i < len(s):
            temp = ""
            if s[i].isdigit():
                while s[i].isdigit():
                    temp += s[i]
                    i += 1
                count_stack.append(int(temp))
            if s[i] == "]":
                times = count_stack.pop()
                temp = ""
                while ch_stack[-1] != "[":
                    temp += ch_stack.pop()[::-1]
                ch_stack.pop()
                temp = temp[::-1]
                ch_stack.append(temp*times)
            else:
                ch_stack.append(s[i])
            i += 1
        decoded = ""
        for ch in ch_stack:
            decoded += ch
        return decoded
