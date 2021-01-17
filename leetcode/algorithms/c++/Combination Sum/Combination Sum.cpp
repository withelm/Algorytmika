class Solution
{
private:
    vector<vector<int>> result;
    vector<int> c;
    void dfs(int n, vector<int> &index, int i)
    {

        if (n < 0)
            return;
        if (n == 0)
        {
            result.push_back(index);
            return;
        }
        if (i >= c.size())
            return;
        for (; i < c.size(); i++)
        {
            index.push_back(c[i]);
            dfs(n - c[i], index, i);
            index.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {

        c = candidates;

        vector<int> tmp = {};
        dfs(target, tmp, 0);
        return result;
    }
};