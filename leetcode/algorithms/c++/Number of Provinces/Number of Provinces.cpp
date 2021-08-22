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
  int findCircleNum(vector<vector<int>> &isConnected) {
    int n = isConnected.size();
    for (int i = 0; i < n; i++)
      base[i] = i;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (isConnected[i][j] == 1)
          u(i, j);
      }
    }

    set<int> r;
    for (auto &x : base)
      r.insert(f(x.first));
    return r.size();
  }
};