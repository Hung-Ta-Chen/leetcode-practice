# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isValidBST(self, root: Optional[TreeNode]) -> bool: 
        def inorder(root, inorder_list):
            if root is None: return
            inorder(root.left, inorder_list)
            inorder_list.append(root.val)
            inorder(root.right, inorder_list)
        inorder_list = []
        inorder(root, inorder_list)
        
        for i in range(1, len(inorder_list)):
            if inorder_list[i] <= inorder_list[i-1]:
                return False
        return True
