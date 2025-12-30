class Solution {
    public boolean isSubtree(TreeNode root, TreeNode subRoot) {
        if (root == null) {
            return false;
        }
      
        return isSameTree(root, subRoot) 
            || isSubtree(root.left, subRoot)
            || isSubtree(root.right, subRoot);
    }

    private boolean isSameTree(TreeNode treeOne, TreeNode treeTwo) {
        if (treeOne == null || treeTwo == null) {
            return treeOne == treeTwo;
        }
      
        return treeOne.val == treeTwo.val 
            && isSameTree(treeOne.left, treeTwo.left) 
            && isSameTree(treeOne.right, treeTwo.right);
    }
}
