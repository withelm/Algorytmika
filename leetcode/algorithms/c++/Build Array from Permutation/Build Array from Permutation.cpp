class Solution {
public:
  vector<int> buildArray(vector<int> &nums) {
    vector<int> r;
    for (auto &x : nums)
      r.push_back(nums[x]);
    return r;
  }
};