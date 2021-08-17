class Solution {
private:
  int calc(string &s) {
    int r = 0;
    for (auto &x : s) {
      r = r * 10 + x - 'a';
    }

    return r;
  }

public:
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    return calc(firstWord) + calc(secondWord) == calc(targetWord);
  }
};