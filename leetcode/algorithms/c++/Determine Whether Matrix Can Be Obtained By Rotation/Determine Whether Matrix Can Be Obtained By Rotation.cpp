class Solution {
private:
  bool check(vector<vector<int>> &m, vector<vector<int>> &t) {
    int x_1 = m.size();

    int y_1 = t.size();

    if (x_1 != y_1)
      return false;
    for (int i = 0; i < x_1; i++)
      for (int j = 0; j < x_1; j++)
        if (m[i][j] != t[i][j])
          return false;
    return true;
  }
  void rotate90(vector<vector<int>> &matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
    for (int i = 0; i < n; i++)
      reverse(matrix[i].begin(), matrix[i].end());
  }

public:
  bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target) {
    for (int i = 0; i < 4; i++) {
      if (check(mat, target))
        return true;
      rotate90(mat);
    }
    return false;
  }
};