
class Compare {
public:
  bool operator()(vector<int> x, vector<int> y) { return x[2] > y[2]; }
};

class Solution {
private:
  int n;
  vector<int> v;
  vector<int> isWather;
  priority_queue<vector<int>, std::vector<vector<int>>, Compare> pq;

  int f(int &x) {
    if (v[x] == x)
      return x;
    return v[x] = f(v[x]);
  }

  void union_f(int x, int y) {
    auto fx_w = isWather[f(x)];
    auto fy_w = isWather[f(y)];

    v[f(x)] = v[f(y)];
    isWather[f(x)] = fx_w == 1 || fy_w == 1;
  }

public:
  int minCostToSupplyWater(int _n, vector<int> &wells,
                           vector<vector<int>> &pipes) {
    n = _n + 1;
    v.resize(n);
    isWather.resize(n);
    for (int i = 0; i < n; i++) {
      v[i] = i;
      isWather[i] = 0;
    }

    for (int i = 1; i < n; i++) {

      pq.push({i, i, wells[i - 1]});
    }
    for (auto &item : pipes) {
      pq.push(item);
    }
    int result = 0;
    while (!pq.empty()) {
      auto item = pq.top();
      pq.pop();
      //  cout << item[0] << " " << item[1] << " " << item[2] << endl;
      if (item[0] == item[1]) {
        if (isWather[f(item[0])] == 0) {
          result += item[2];
          isWather[f(item[0])] = 1;
        }
      } else {
        int f_x = f(item[0]);

        int f_y = f(item[1]);

        if (f_x == f_y)
          continue;
        if (isWather[f_x] == 1 && isWather[f_y] == 1)
          continue;

        union_f(f_x, f_y);
        result += item[2];
      }
    }

    return result;
  }
};