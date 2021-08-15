class Solution {
public:
  int minFlipsMonoIncr(string s) {
    int result = 1e9;

    int zeros = 0;
    int ones = 0;
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if (s[i] == '0')
        ++zeros;
    }

    for (int i = 0; i < n; i++) {

      result = min(result, zeros + ones);

      if (s[i] == '0')
        --zeros;
      else
        ++ones;
    }
    result = min(result, zeros + ones);
    return result;
  }
};