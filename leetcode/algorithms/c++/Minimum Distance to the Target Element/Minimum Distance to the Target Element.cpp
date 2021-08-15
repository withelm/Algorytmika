class Solution {
public:
  int getMinDistance(vector<int> &nums, int target, int start) {
    int r = 1e9;

    for (int i = 0; i < nums.size(); i++) {
      if (nums[i] == target)
        r = min(r, abs(i - start));
    }
    return r;
  }
};