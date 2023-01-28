# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

"""
In the iteration, we push all the left nodes we can reach from given root into the stack
(Just like we always do to left child first in recursion)
Then whenever we pop a node out from stack, we set the current root to the right child
(Just like what we do after we finish the left side of a given node in recursion)
"""
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool: 
        stack = []
        inorder_last = None
        curr = root
        while curr or stack:
            while curr:
                stack.append(curr)
                curr = curr.left
            top = stack.pop()
            if inorder_last is None:
                inorder_last = top.val
            else:
                if top.val <= inorder_last:
                    return False
                else:
                    inorder_last = top.val
            curr = top.right
        return True
            
