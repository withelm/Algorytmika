class Solution {
public:
  bool areOccurrencesEqual(string s) {
    map<int, int> base;
    for (auto &x : s)
      ++base[x];
    set<int> res;
    for (auto &x : base)
      res.insert(x.second);
    return res.size() == 1;
  }
};