# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool: 
        def isLegalNode(root: Optional[TreeNode], low_bound=-math.inf, high_bound=math.inf) -> bool:
            if root == None: return True
            if root.val <= low_bound: return False
            if root.val >= high_bound: return False
            return isLegalNode(root.left, low_bound, root.val) and isLegalNode(root.right, root.val, high_bound)
        return isLegalNode(root)
