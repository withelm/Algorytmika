class Solution
{
private:
    int INF = 1e9;

public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> p(n + 2, 0);
        for (int i = 0; i < n; i++)
            p[i + 1] = p[i] + nums[i];
        p[n + 1] = INF;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j + i <= n; j++)
            {
                if (p[j + i] - p[j] >= s)
                    return i;
            }
        }

        return 0;
    }
};