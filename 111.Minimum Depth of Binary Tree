class Solution(object):
    def minDepth(self, root):
        if root is None:
            return 0
        left_depth = self.minDepth(root.left)
        right_depth = self.minDepth(root.right)
        if left_depth > 0 and right_depth > 0:
            return min(left_depth, right_depth) + 1
        elif left_depth == 0 and right_depth == 0:
            return 1
        elif left_depth > 0:
            return left_depth + 1
        else:  # right_depth > 0
            return right_depth + 1
