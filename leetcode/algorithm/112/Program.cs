using System;

namespace _112
{

    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int x) { val = x; }
    }

    public class Solution
    {
        public static bool _isEnd = false;
        public bool HasPathSum(TreeNode root, int sum)
        {
            _isEnd = false;
            if (root == null)
            {
                return false;
            }
            return dfs(root, sum);
        }

        bool dfs(TreeNode x, int s)
        {
            if (_isEnd)
                return true;
            if (x.right == null && x.left == null)
            {
                if (x.val == s)
                    _isEnd = true;
                return x.val == s;
            }
            if (x.right != null && x.left != null)
                return dfs(x.left, s - x.val) || dfs(x.right, s - x.val);
            if (x.right != null && x.left == null)
                return dfs(x.right, s - x.val);
            if (x.right == null && x.left != null)
                return dfs(x.left, s - x.val);
            return false;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            
        }
    }
}
