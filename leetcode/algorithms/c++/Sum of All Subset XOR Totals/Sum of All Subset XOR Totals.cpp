class Solution {
public:
  int subsetXORSum(vector<int> &nums) {
    int result = 0;
    int n = nums.size();
    int limit = 1 << n;

    for (int i = 0; i < limit; i++) {

      int tmp = 0;
      int val = i;
      for (int j = 0; j < n; j++) {
        if (val % 2 == 1)
          tmp ^= nums[j];
        val /= 2;
      }

      result += tmp;
    }
    return result;
  }
};