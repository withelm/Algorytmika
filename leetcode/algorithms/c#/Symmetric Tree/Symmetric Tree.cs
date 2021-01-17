/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int x) { val = x; }
 * }
 */
public class Solution
{
    public bool IsSymmetric(TreeNode root)
    {
        if (root == null) return true;
        return dfs(root.left, root.right);
    }

    public bool dfs(TreeNode p, TreeNode q)
    {
        if (p == null && q != null) return false;
        if (p != null && q == null) return false;
        if (p == null && q == null) return true;

        if (p.val != q.val) return false;
        return dfs(p.left, q.right) && dfs(p.right, q.left);
    }
}