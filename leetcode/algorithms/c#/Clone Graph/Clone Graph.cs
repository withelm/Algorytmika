/*
// Definition for a Node.
public class Node {
    public int val;
    public IList<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new List<Node>();
    }

    public Node(int _val) {
        val = _val;
        neighbors = new List<Node>();
    }

    public Node(int _val, List<Node> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
}
*/
public class Solution
{
    private Dictionary<Node, Node> dict = new Dictionary<Node, Node>();

    public Node CloneGraph(Node node)
    {
        if (node == null) return null;
        if (dict.ContainsKey(node)) return dict[node];
        var res = new Node(node.val);
        dict.Add (node, res);
        foreach (var item in node.neighbors)
        res.neighbors.Add(CloneGraph(item));

        return res;
    }
}
