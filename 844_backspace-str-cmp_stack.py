class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        def showString(s) -> list:
            stack = []
            for ch in s:
                if ch == '#':
                    if stack:
                        stack.pop()
                else:
                    stack.append(ch)
            return stack
        return showString(s) == showString(t)
