class Solution
{

private:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(vector<int> &use, int n, int k, int i)
    {
        bool isFree = false;
        for (int i = 1; i <= n; i++)
        {
            if (use[i] == 0)
            {
                isFree = true;
                break;
            }
        }
        if (!isFree)
            return;
        if (k == 0)
        {

            ans.push_back(tmp);
        }

        for (; i <= n; i++)
        {
            if (use[i] == 0)
            {
                use[i] = 1;
                tmp.push_back(i);
                dfs(use, n, k - 1, i + 1);
                tmp.pop_back();
                use[i] = 0;
            }
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {

        if (n == k)
        {
            vector<int> tmp;
            for (int i = 1; i <= n; i++)
                tmp.push_back(i);
            return {tmp};
        }

        vector<int> use(n + 1, 0);
        dfs(use, n, k, 1);
        return ans;
    }
};