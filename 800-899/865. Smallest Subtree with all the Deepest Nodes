class Solution:
    def subtreeWithAllDeepest(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        def dfs(root: Optional[TreeNode]) -> Tuple[Optional[TreeNode], int]:
            if root is None:
                return None, 0
            l, ld = dfs(root.left)
            r, rd = dfs(root.right)
            if ld > rd:
                return l, ld + 1
            if ld < rd:
                return r, rd + 1
            return root, ld + 1
        return dfs(root)[0]
        
