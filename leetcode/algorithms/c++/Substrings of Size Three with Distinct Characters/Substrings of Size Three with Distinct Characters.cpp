class Solution {
private:
  bool check(map<int, int> &x) {
    for (auto &i : x) {
      if (i.second > 1)
        return false;
    }
    return true;
  }

public:
  int countGoodSubstrings(string s) {
    int r = 0;
    int n = s.size();
    if (n < 3)
      return r;
    map<int, int> base;
    for (int i = 0; i < 3; i++)
      ++base[s[i]];

    for (int i = 3; i < n; i++) {
      r += check(base);
      --base[s[i - 3]];
      ++base[s[i]];
    }
    return r + check(base);
  }
};