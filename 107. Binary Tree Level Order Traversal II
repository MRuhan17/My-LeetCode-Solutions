class Solution(object):
    def levelOrderBottom(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root is None:
            return []
        
        result = []
        nodes1 = [root]
        nodes2 = []
        
        while nodes1:
            cur_result = []
            for node in nodes1:
                cur_result.append(node.val)
                if node.left:
                    nodes2.append(node.left)
                if node.right:
                    nodes2.append(node.right)
            
            result.append(cur_result)
            nodes1, nodes2 = nodes2, []  # swap for next level
        
        return list(reversed(result))
