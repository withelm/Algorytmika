class Solution {
public:
  bool makeEqual(vector<string> &words) {
    map<int, int> base;
    for (auto &word : words)
      for (auto &x : word)
        ++base[x];
    for (auto &x : base) {
      if (x.second % words.size() != 0)
        return false;
    }
    return true;
  }
};