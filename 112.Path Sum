class Solution(object):
    def hasPathSum(self, root, targetSum):
        if root is None:
            return False
        if root.left is None and root.right is None:
            return targetSum == root.val
        left_ans = self.hasPathSum(root.left, targetSum - root.val)
        right_ans = self.hasPathSum(root.right, targetSum - root.val)
        return left_ans or right_ans
