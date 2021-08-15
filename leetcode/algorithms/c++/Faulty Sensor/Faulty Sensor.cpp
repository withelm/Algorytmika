class Solution {
public:
  int badSensor(vector<int> &x, vector<int> &y) {
    int n = x.size();
    int index = 0;
    while (index < n && x[index] == y[index])
      ++index;
    if (index == n)
      return -1;

    auto q1 =
        equal(x.begin() + index + 1, x.end(), y.begin() + index, y.end() - 1);
    auto q2 =
        equal(y.begin() + index + 1, y.end(), x.begin() + index, x.end() - 1);

    if (q1 == q2)
      return -1;
    if (q1)
      return 2;
    return 1;
  }
};