class Solution {
private:
  set<string> cnt;
  int n;
  string repair(string &x) {
    if (x == "")
      return "";
    bool isNoZero = false;
    string res = "";
    for (auto &i : x) {
      if (i == '0' && !isNoZero)
        continue;
      if (i != '0')
        isNoZero = true;
      res.push_back(i);
    }
    return res == "" ? "0" : res;
  }

public:
  int numDifferentIntegers(string word) {
    n = word.size();
    string part = "";
    for (int i = 0; i < n; i++) {
      if (word[i] >= '0' && word[i] <= '9') {
        part += word[i];
      } else {
        part = repair(part);
        if (part != "") {
          cnt.insert(part);
          part = "";
        }
      }
    }
    part = repair(part);
    if (part != "") {
      cnt.insert(part);
      part = "";
    }

    return cnt.size();
  }
};