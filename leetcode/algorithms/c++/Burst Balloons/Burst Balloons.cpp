class Solution
{
private:
    vector<vector<int>> t;
    int n;

    int dp(int left, int right, vector<int> &nums)
    {
        if (left + 1 == right)
            return 0;

        if (t[left][right] > 0)
            return t[left][right];

        int tmp = 0;
        for (int i = left + 1; i < right; i++)
        {
            int val = 1;

            tmp = max(tmp, nums[left] * nums[i] * nums[right] + dp(left, i, nums) + dp(i, right, nums));
        }
        return t[left][right] = tmp;
    }

public:
    int maxCoins(vector<int> &nums)
    {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        n = nums.size();
        t.resize(n);
        for (auto &i : t)
            i.resize(n);
        return dp(0, n - 1, nums);
    }
};