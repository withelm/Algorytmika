/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
  int res = -1e9;

  int dfs(Node *root) {
    if (root == NULL)
      return 0;
    vector<int> t;
    for (auto item : root->children) {
      int len = dfs(item);
      if (len > 0)
        t.push_back(len);
    }
    sort(t.begin(), t.end(), greater<int>());
    res = max(1, res);
    if (t.size() == 0)
      return 1;

    res = max(t[0] + 1, res);

    if (t.size() == 1)
      return t[0] + 1;
    res = max(t[0] + t[1] + 1, res);

    return t[0] + 1;
  }

public:
  int diameter(Node *root) {
    dfs(root);
    return res - 1;
  }
};