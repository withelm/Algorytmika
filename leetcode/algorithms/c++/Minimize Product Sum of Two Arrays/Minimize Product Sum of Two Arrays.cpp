class Solution {
public:
  int minProductSum(vector<int> &nums1, vector<int> &nums2) {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int res = 0;
    int n = nums1.size();
    for (int i = 0; i < n; i++)
      res += nums1[i] * nums2[n - i - 1];
    return res;
  }
};