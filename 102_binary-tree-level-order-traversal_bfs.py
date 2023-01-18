# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None: return []
        queue, order = collections.deque(), []
        queue.append(root)
        while queue:
            temp = []
            size = len(queue)
            for i in range(size):
                top = queue.popleft()
                temp.append(top.val)
                if top.left is not None: queue.append(top.left)
                if top.right is not None: queue.append(top.right)
            order.append(temp)
        return order
