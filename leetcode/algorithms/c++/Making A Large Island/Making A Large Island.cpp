class Solution {
private:
  vector<vector<int>> moves{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  vector<int> base;
  vector<int> size;

  int n;

  int f(int &x) {
    if (x == base[x])
      return x;

    return base[x] = f(base[x]);
  }

  void union_f(int x, int y) {
    auto f_x = f(x);
    auto f_y = f(y);
    if (f_x == f_y)
      return;

    size[f_x] += size[f_y];
    base[f_y] = f_x;
  }

public:
  int largestIsland(vector<vector<int>> &grid) {
    n = grid.size();
    base.resize(n * n);
    size.resize(n * n);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        base[i * n + j] = i * n + j;
        size[i * n + j] = grid[i][j];
      }
    }
    int res = 1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0)
          continue;
        for (auto &move : moves) {
          int x = i + move[0];
          int y = j + move[1];
          if (x < 0 || y < 0 || x >= n || y >= n)
            continue;
          if (grid[x][y] == 1) {
            union_f(i * n + j, x * n + y);
          }
        }
        int tmp = i * n + j;
        res = max(res, size[f(tmp)]);
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (grid[i][j] == 0) {
          set<int> l;
          for (auto &move : moves) {
            int x = i + move[0];
            int y = j + move[1];
            if (x < 0 || y < 0 || x >= n || y >= n)
              continue;
            int tmp = x * n + y;
            l.insert(f(tmp));
          }
          int sum = 1;
          for (auto &item : l)
            sum += size[item];
          res = max(res, sum);
        }
      }
    }

    return res;
  }
};