# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        self.dep = 0
        def dfs(head, depth):
            if not head:
                self.dep = max(self.dep, depth-1)
                return
            dfs(head.left, depth+1)
            dfs(head.right, depth+1)

        dfs(root, 1)
        return self.dep