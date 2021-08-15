class Solution {
private:
  map<int, map<int, int>> dps;
  map<int, map<int, vector<vector<int>>>> vToIndex;

  vector<int> row, col;

  int n, m;

  int find(map<int, int> &dp, int x) {
    if (x != dp[x]) {
      return dp[x] = find(dp, dp[x]);
    }
    return x;
  }

  void merge(map<int, int> &dp, int x, int y) {
    if (dp.find(x) == dp.end())
      dp[x] = x;
    if (dp.find(y) == dp.end())
      dp[y] = y;
    dp[find(dp, x)] = dp[find(dp, y)];
  }

public:
  vector<vector<int>> matrixRankTransform(vector<vector<int>> &matrix) {
    n = matrix.size();
    m = matrix[0].size();

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int val = matrix[i][j];
        merge(dps[val], i, ~j);
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int val = matrix[i][j];
        int find_val = find(dps[val], i);
        vToIndex[val][find_val].push_back({i, j});
      }
    }

    vector<vector<int>> r(n, vector<int>(m));
    row.resize(n, 0);
    col.resize(m, 0);

    for (auto &item : vToIndex) {
      for (auto &ent : item.second) {
        auto points = ent.second;
        int rank = 1;
        for (auto &point : points) {
          rank = max(rank, max(row[point[0]], col[point[1]]) + 1);
        }

        for (auto &point : points) {
          r[point[0]][point[1]] = rank;
          row[point[0]] = max(row[point[0]], rank);
          col[point[1]] = max(col[point[1]], rank);
        }
      }
    }
    return r;
  }
};