class Solution {
public:
  bool isDecomposable(string s) {
    int n = s.size();
    if (n == 0)
      return false;

    char last = s[0];
    int cnt = 1;
    map<int, int> base;
    vector<int> r;
    for (int i = 1; i < n; i++) {
      if (s[i] == last)
        ++cnt;
      else {
        ++base[cnt % 3];
        cnt = 1;
        last = s[i];
      }
    }
    ++base[cnt % 3];

    return base[2] == 1 && base[1] == 0;
  }
};