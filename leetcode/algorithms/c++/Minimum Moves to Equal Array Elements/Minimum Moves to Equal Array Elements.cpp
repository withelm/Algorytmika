class Solution
{

public:
    int minMoves(vector<int> &nums)
    {
        int k = 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 1; i < n; i++)
            k += nums[i] - nums[0];

        return k;
    }
};