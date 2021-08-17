class Solution {
private:
  map<int, int> base;
  int f(int x) {
    if (base[x] != x)
      return base[x] = f(base[x]);
    return x;
  }
  void u(int x, int y) { base[f(x)] = base[f(y)]; }

public:
  bool validPath(int n, vector<vector<int>> &edges, int start, int end) {
    for (int i = 0; i < n; i++)
      base[i] = i;
    for (auto &edge : edges)
      u(edge[0], edge[1]);
    return f(start) == f(end);
  }
};