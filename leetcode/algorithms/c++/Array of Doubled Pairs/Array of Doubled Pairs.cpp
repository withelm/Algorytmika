class Solution {
public:
  bool canReorderDoubled(vector<int> &arr) {
    map<int, int> kub;
    for (auto &x : arr)
      ++kub[x];

    for (auto &x : kub) {
      if (x.second > 0) {
        if (x.first == 0 && x.second % 2 == 1)
          return false;
        if (x.first > 0) {
          if (x.second > kub[x.first * 2])
            return false;
          kub[x.first * 2] -= x.second;
          x.second = 0;
        }
        if (x.first < 0 && x.first % 2 == 0) {
          if (x.second > kub[x.first / 2])
            return false;
          kub[x.first / 2] -= x.second;
          x.second = 0;
        }
        if (x.first < 0 && x.first % 2 == -1)
          return false;
      }
    }
    return true;
  }
};