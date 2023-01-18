"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    def preorder(self, root: 'Node') -> List[int]:
        if root is None: return []
        stack, order = [], []
        stack.append(root)
        while stack:
            top = stack.pop()
            order.append(top.val)
            # Note that we have to reverse the children list (LIFO)
            # we can use top.children[::-1] or reversed(top.children)
            # We can also just use extend() instead of a loop
            for child in reversed(top.children):
                stack.append(child)
        return order
