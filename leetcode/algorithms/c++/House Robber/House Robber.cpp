class Solution
{
private:
    vector<int> t, m;

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        m = nums;
        t.resize(n + 10);
        t[0] = m[0];
        t[1] = max(m[0], m[1]);
        for (int i = 2; i < n; i++)
        {

            t[i] = max(t[i - 2] + m[i], t[i - 1]);
        }
        return t[n - 1];
    }
};