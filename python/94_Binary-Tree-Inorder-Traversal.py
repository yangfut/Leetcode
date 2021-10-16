# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        queue = []
        def getInorderNode(node):
            if node == None: return
            getInorderNode(node.left)
            queue.append(node.val)
            getInorderNode(node.right)
        getInorderNode(root)
        return queue
                
        
