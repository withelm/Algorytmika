class Solution {
private:
  int calc(int x) {
    int r = 0;
    while (x > 0) {
      r += x % 10;
      x /= 10;
    }
    return r;
  }

public:
  int getLucky(string s, int k) {
    string num = "";
    for (int i = 0; i < s.size(); i++) {
      int val = s[i] - 'a' + 1;
      if (val > 9) {
        num += (val / 10) + '0';
      }
      num += (val % 10) + '0';
    }
    int result = 0;
    for (auto &x : num)
      result += x - '0';
    --k;
    while (k-- > 0)
      result = calc(result);

    return result;
  }
};