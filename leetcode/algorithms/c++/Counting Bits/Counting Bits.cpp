class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> r;
    for (int i = 0; i <= n; i++) {
      r.push_back(__builtin_popcount(i));
    }
    return r;
  }
};