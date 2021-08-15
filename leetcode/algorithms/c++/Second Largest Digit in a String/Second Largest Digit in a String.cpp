class Solution {
private:
  map<int, int> kub;

public:
  int secondHighest(string s) {
    for (auto &x : s)
      ++kub[x];

    bool isUsed = false;
    for (int i = '9'; i >= '0'; i--) {
      if (kub[i] > 0 && !isUsed) {
        isUsed = true;
      } else if (kub[i] > 0 && isUsed) {
        return i - '0';
      }
    }
    return -1;
  }
};