class Solution {
private:
  vector<vector<vector<int>>> dp;
  vector<int> t;
  int n;

  int dfs(int l, int r, int k) {
    if (l > r)
      return 0;
    while (r > l && t[r] == t[r - 1]) {
      --r;
      ++k;
    }

    if (dp[l][r][k] != 0)
      return dp[l][r][k];
    dp[l][r][k] = dfs(l, r - 1, 0) + (k + 1) * (k + 1);

    for (int i = l; i < r; i++) {
      if (t[i] == t[r]) {
        dp[l][r][k] = max(dp[l][r][k], dfs(l, i, k + 1) + dfs(i + 1, r - 1, 0));
      }
    }
    return dp[l][r][k];
  }

public:
  int removeBoxes(vector<int> &boxes) {
    t = boxes;
    n = t.size();
    dp.resize(n, vector<vector<int>>(n, vector<int>(n, 0)));
    return dfs(0, n - 1, 0);
  }
};