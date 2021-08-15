class Solution {
public:
  int maxAscendingSum(vector<int> &nums) {
    int result = *max_element(nums.begin(), nums.end());

    int part = nums[0];
    for (int i = 1; i < nums.size(); i++) {
      if (nums[i - 1] < nums[i])
        part += nums[i];
      else {
        result = max(result, part);
        part = nums[i];
      }
    }
    return max(result, part);
  }
};