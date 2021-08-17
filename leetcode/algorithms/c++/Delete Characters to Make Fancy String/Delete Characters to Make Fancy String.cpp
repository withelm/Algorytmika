class Solution {
public:
  string makeFancyString(string t) {
    int n = t.size();
    if (n < 3)
      return t;
    char f = t[0];
    char s = t[1];

    for (int i = 2; i < n; i++) {
      if (f == s && s == t[i]) {
        t[i] = 0;
      } else {
        f = s;
        s = t[i];
      }
    }
    string r;
    for (auto &x : t)
      if (x != 0)
        r.push_back(x);
    return r;
  }
};