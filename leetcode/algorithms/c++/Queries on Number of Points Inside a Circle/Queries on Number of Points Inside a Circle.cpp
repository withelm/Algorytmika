class Solution {
private:
  inline int distance(vector<int> &x, vector<int> y) {
    return (x[0] - y[0]) * (x[0] - y[0]) + (x[1] - y[1]) * (x[1] - y[1]);
  }

  inline int check(vector<int> &point, vector<int> &query) {
    return distance(point, {query[0], query[1]}) <= query[2] * query[2];
  }

  inline int calc(vector<vector<int>> &points, vector<int> &query) {
    int res = 0;
    for (auto &point : points) {
      res += check(point, query);
    }
    return res;
  }

public:
  vector<int> countPoints(vector<vector<int>> &points,
                          vector<vector<int>> &queries) {
    vector<int> res;

    for (auto &query : queries) {
      res.push_back(calc(points, query));
    }

    return res;
  }
};