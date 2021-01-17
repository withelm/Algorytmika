class Solution
{
private:
    vector<int> dfs(int val, int last, int deep, int n, int k)
    {
        vector<int> result;
        if (deep == n)
        {
            return {val};
        }
        if (last - k >= 0)
        {
            auto tmp = dfs(val * 10 + (last - k), (last - k), deep + 1, n, k);
            for (auto &x : tmp)
            {
                result.push_back(x);
            }
        }

        if (last - k != last + k && last + k <= 9)
        {
            auto tmp2 = dfs(val * 10 + (last + k), last + k, deep + 1, n, k);
            for (auto &x : tmp2)
            {
                result.push_back(x);
            }
        }
        return result;
    }

public:
    vector<int> numsSameConsecDiff(int N, int K)
    {
        vector<int> result;
        for (int i = (N == 1) ? 0 : 1; i <= 9; i++)
        {
            auto tmp = dfs(i, i, 1, N, K);
            for (auto &x : tmp)
            {
                result.push_back(x);
            }
        }

        return result;
    }
};