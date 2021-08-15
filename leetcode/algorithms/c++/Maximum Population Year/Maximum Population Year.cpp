class Solution {
private:
  map<int, int> base;

public:
  int maximumPopulation(vector<vector<int>> &logs) {
    for (int i = 1950; i <= 2050; i++) {
      for (auto &log : logs) {
        base[i] += log[0] <= i && i < log[1];
      }
    }

    int r = 1950;
    int pop = -1;
    for (int i = 1950; i <= 2050; i++) {
      if (pop < base[i]) {
        r = i;
        pop = base[i];
      }
    }
    return r;
  }
};