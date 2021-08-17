class Solution {
public:
  string largestOddNumber(string num) {
    int n = num.size() - 1;
    while (n >= 0 && (num[n] - '0') % 2 == 0)
      --n;
    string r = "";
    for (int i = 0; i <= n; i++)
      r += num[i];
    return r;
  }
};