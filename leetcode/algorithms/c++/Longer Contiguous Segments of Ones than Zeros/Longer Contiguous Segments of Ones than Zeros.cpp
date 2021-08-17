class Solution {
public:
  bool checkZeroOnes(string s) {
    int one = 0;
    int zero = 0;
    int tmp = 0;
    int last = 0;
    for (int i = 0; i < s.size(); i++) {
      if (last != s[i]) {
        if (last == '0')
          zero = max(zero, tmp);
        if (last == '1')
          one = max(one, tmp);
        tmp = 1;
      } else {
        ++tmp;
      }
      last = s[i];
    }
    if (last == '0')
      zero = max(zero, tmp);
    if (last == '1')
      one = max(one, tmp);
    return one > zero;
  }
};