# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root, p, q):
        def LCA(root, p, q):
            if root.val > p.val and root.val > q.val:
                return LCA(root.left, p, q)
            elif root.val < p.val and root.val < q.val:
                return LCA(root.right, p, q)
            else:
                # 1. Two nodes are in the different child
                # 2. One of the two nodes equals the root
                return root
        return LCA(root, p, q)
