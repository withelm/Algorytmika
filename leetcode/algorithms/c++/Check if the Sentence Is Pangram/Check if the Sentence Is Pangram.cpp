class Solution {
public:
  bool checkIfPangram(string sentence) {
    map<int, int> base;
    for (auto &x : sentence)
      ++base[x];
    for (int i = 'a'; i <= 'z'; i++)
      if (base[i] == 0)
        return false;
    return true;
  }
};