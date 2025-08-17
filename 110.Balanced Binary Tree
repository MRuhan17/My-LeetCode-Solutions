class Solution(object):
    def solve(self, root):
        if root is None:
            return True, 0
        ans1, height1 = self.solve(root.left)
        ans2, height2 = self.solve(root.right)
        if ans1 is False or ans2 is False:
            return False, 0
        if abs(height1 - height2) > 1:
            return False, 0
        return True, max(height1, height2) + 1

    def isBalanced(self, root):
        ans, _ = self.solve(root)
        return ans
