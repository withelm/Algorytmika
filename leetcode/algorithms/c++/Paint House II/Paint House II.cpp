class Solution {
private:
  int n, m;

public:
  int minCostII(vector<vector<int>> &costs) {
    n = costs.size();
    m = costs[0].size();

    for (int i = 1; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int minimum = 1e9;

        for (int k = 0; k < m; k++) {
          if (k == j)
            continue;

          minimum = min(minimum, costs[i - 1][k]);
        }

        costs[i][j] += minimum;
      }
    }

    int minimum = 1e9;

    for (int i = 0; i < m; i++)
      minimum = min(minimum, costs[n - 1][i]);
    return minimum;
  }
};