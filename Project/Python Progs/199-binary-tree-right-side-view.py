# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        self.res = []
        queue = [root]
        while queue:
            self.res.append(queue[-1].val)
            temp = queue.copy()
            queue.clear()
            for node in temp:
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
        
        return self.res