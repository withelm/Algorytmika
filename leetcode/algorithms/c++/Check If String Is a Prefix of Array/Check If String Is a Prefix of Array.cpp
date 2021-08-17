class Solution {
public:
  bool isPrefixString(string s, vector<string> &words) {
    string result = "";
    int i = 0;
    int n = words.size();
    while (i < n && result != s) {
      result += words[i++];
    }

    return result == s;
  }
};