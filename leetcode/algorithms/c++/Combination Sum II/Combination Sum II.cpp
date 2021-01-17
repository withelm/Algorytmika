class Solution
{
private:
    set<vector<int>> result;
    vector<int> c;
    void dfs(int n, vector<int> &index, int i)
    {

        if (n < 0)
            return;
        if (n == 0)
        {
            result.insert(index);
            return;
        }
        if (i >= c.size())
            return;
        for (; i < c.size(); i++)
        {
            index.push_back(c[i]);
            dfs(n - c[i], index, i + 1);
            index.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        c = candidates;

        vector<int> tmp = {};
        dfs(target, tmp, 0);

        vector<vector<int>> r;
        for (auto &x : result)
        {
            r.push_back(x);
        }

        return r;
    }
};