class Solution
{
private:
    vector<vector<int>> next;
    int r;
    vector<bool> vis;

    void back(int k, int n)
    {
        // cout << k << " " << n << endl;
        // for(int i = 1; i <= n; i++) cout << vis[i] << " ";
        //  cout << endl;

        if (k == n + 1)
        {
            ++r;
            return;
        }
        for (auto &i : next[k])
        {
            if (!vis[i])
            {
                vis[i] = true;
                back(k + 1, n);
                vis[i] = false;
            }
        }
    }

public:
    int countArrangement(int n)
    {

        next.resize(20);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (j % i == 0)
                    next[i].push_back(j);
                else if (i % j == 0)
                    next[i].push_back(j);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            cout << i << ": ";
            for (auto &x : next[i])
                cout << x << " ";
            cout << endl;
        }

        vis.resize(n + 1);
        for (int i = 0; i < n + 1; i++)
            vis[i] = false;

        back(1, n);

        return r;
    }
};