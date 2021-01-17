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
    public int MaxDepth(TreeNode root)
    {
        return dfs(root, 0);
    }

    public int dfs(TreeNode x, int v)
    {
        if (x == null) return v;
        int v1 = dfs(x.left, v + 1);
        int v2 = dfs(x.right, v + 1);
        return v1 < v2 ? v2 : v1;
    }
}