/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution
{
    public TreeNode InsertIntoBST(TreeNode root, int val)
    {
        if (root == null) return new TreeNode(val);

        TreeNode x = root;
        while (x != null)
        {
            if (x.val > val)
            {
                if (x.left == null) break;
                x = x.left;
            }
            else
            {
                if (x.right == null) break;
                x = x.right;
            }
        }
        var tmp = new TreeNode();
        tmp.val = val;
        if (x.val > val) x.left = tmp;
        else x.right = tmp;

        return root;
    }
}