class Solution {
private:
  pair<string, int> convert(string &x) {
    string result = "";
    int index = 0;

    for (int i = 0; i < x.size(); i++) {
      if (x[i] >= '0' && x[i] <= '9')
        index = index * 10 + x[i] - '0';
      else
        result += x[i];
    }

    return {result, index};
  }

public:
  string sortSentence(string s) {
    vector<string> txt(200, "");
    int n = s.size();
    int index = 0;
    while (index < n) {
      string tmp = "";
      while (index < n && s[index] != ' ') {
        tmp += s[index];
        ++index;
      }
      ++index;
      auto better_tmp = convert(tmp);
      txt[better_tmp.second - 1] = better_tmp.first;
    }
    string result = "";
    for (int i = 0; i < 200; i++) {
      if (txt[i] == "")
        break;
      if (result != "")
        result += " ";
      result += txt[i];
    }

    return result;
  }
};