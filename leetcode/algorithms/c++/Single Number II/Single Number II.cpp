class Solution {
private:
  int MX = 32;
  vector<int> arr;

public:
  int singleNumber(vector<int> &nums) {
    arr.resize(MX, 0);

    for (auto &x : nums) {

      for (int i = 0; i < MX; i++) {

        if ((x & (1 << i)) == (1 << i))
          ++arr[i];
      }
    }

    int res = 0;
    for (int i = 0; i < MX; i++) {
      if (arr[i] > 0 && arr[i] % 3 != 0)
        res += 1 << i;
    }
    return res;
  }
};