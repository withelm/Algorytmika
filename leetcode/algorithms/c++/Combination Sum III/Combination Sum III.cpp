class Solution
{
private:
    vector<vector<int>> result;
    void dfs(int k, int n, vector<int> &index)
    {
        if (k != 0)
        {
            for (int i = index.size() == 0 ? 1 : index.back() + 1; i <= 9; i++)
            {
                index.push_back(i);
                dfs(k - 1, n - i, index);
                index.pop_back();
            }
        }
        else
        {
            if (n == 0)
            {
                result.push_back(index);
            }
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        if (1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 < n || k > 9)
            return {};

        vector<int> tmp = {};
        dfs(k, n, tmp);
        return result;
    }
};