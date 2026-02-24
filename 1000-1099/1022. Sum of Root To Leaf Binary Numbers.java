class Solution {
    public int sumRootToLeaf(TreeNode root) {
        return dfs(root, 0);
    }

    private int dfs(TreeNode root, int x) {
        if (root == null) {
            return 0;
        }
        x = x << 1 | root.val;
        if (root.left == root.right) {
            return x;
        }
        return dfs(root.left, x) + dfs(root.right, x);
    }
}
