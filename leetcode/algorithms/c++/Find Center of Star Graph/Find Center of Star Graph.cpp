class Solution {
private:
  map<int, int> kub;
  int n;

public:
  int findCenter(vector<vector<int>> &edges) {
    for (auto &edge : edges) {
      ++kub[edge[0]];
      ++kub[edge[1]];
      n = max(n, edge[0]);
      n = max(n, edge[1]);
    }
    for (auto &item : kub) {
      if (item.second == n - 1)
        return item.first;
    }
    return -1;
  }
};