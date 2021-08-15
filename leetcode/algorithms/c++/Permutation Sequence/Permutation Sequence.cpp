class Solution {
public:
  string getPermutation(int n, int k) {
    string t = "";
    --k;
    for (int i = 0; i < n; i++)
      t += i + 1 + '0';

    while (k--) {
      next_permutation(t.begin(), t.end());
    }
    return t;
  }
};