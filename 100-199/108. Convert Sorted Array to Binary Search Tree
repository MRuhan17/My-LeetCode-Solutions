class Solution(object):
    def sortedArrayToBST(self, nums):
        if len(nums) == 0:
            return None
        cur_ind = len(nums) // 2
        cur_node = TreeNode(nums[cur_ind])
        left_nums = nums[:cur_ind]
        right_nums = nums[cur_ind + 1:]
        if len(left_nums) > 0:
            cur_node.left = self.sortedArrayToBST(left_nums)
        if len(right_nums) > 0:
            cur_node.right = self.sortedArrayToBST(right_nums)
        return cur_node
