/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left),
 * right(right), random(random) {}
 * };
 */

class Solution {
private:
  map<Node *, NodeCopy *> mem;

  NodeCopy *dfs(Node *root) {
    if (root == NULL)
      return NULL;
    if (mem[root] != NULL)
      return mem[root];
    return mem[root] =
               new NodeCopy(root->val, dfs(root->left), dfs(root->right), NULL);
  }

  NodeCopy *repair(NodeCopy *copy, Node *root) {
    if (copy == NULL)
      return NULL;
    if (root == NULL)
      return NULL;
    if (root->random != NULL) {
      copy->random = mem[root->random];
    }
    repair(copy->left, root->left);
    repair(copy->right, root->right);

    return copy;
  }

public:
  NodeCopy *copyRandomBinaryTree(Node *root) {
    NodeCopy *copy = dfs(root);
    return repair(copy, root);
  }
};