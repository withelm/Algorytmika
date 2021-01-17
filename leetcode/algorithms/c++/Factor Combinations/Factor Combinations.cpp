class Solution
{

private:
    vector<vector<int>> r;
    set<vector<int>> res;
    void dfs(vector<int> base, int n)
    {
        if (n == 1 && base.size() > 1)
        {
            sort(base.begin(), base.end());
            res.insert(base);
        }
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0)
            {
                base.push_back(i);
                dfs(base, n / i);
                base.pop_back();
            }
        }
    }

public:
    vector<vector<int>> getFactors(int n)
    {
        dfs({}, n);
        for (auto &x : res)
            r.push_back(x);
        return r;
    }
};