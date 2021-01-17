class Solution
{
private:
    map<int, vector<int>> base;

    int n;

public:
    int minJumps(vector<int> &arr2)
    {

        if (arr2.size() == 1)
            return 0;

        vector<int> arr;
        vector<int> vis(arr2.size(), true);

        for (int i = 1; i + 1 < arr2.size(); i++)
        {
            if (arr2[i - 1] == arr2[i] && arr2[i] == arr2[i + 1])
            {
                vis[i] = false;
            }
        }
        for (int i = 0; i < arr2.size(); i++)
        {
            if (vis[i])
                arr.push_back(arr2[i]);
        }

        // for(auto &x : arr) cout << x << " ";
        // cout << endl;

        n = arr.size();
        vector<int> g[n];
        vector<bool> v(n, false);

        for (int i = 0; i < n; i++)
        {
            if (i + 1 < n)
            {
                g[i].push_back(i + 1);
                g[i + 1].push_back(i);
            }
            if (i - 1 >= 0)
            {
                g[i].push_back(i - 1);
                g[i - 1].push_back(i);
            }
            base[arr[i]].push_back(i);
        }
        for (auto &x : base)
        {
            int m = x.second.size();
            for (int i = 0; i < m; i++)
            {
                for (int j = i + 1; j < m; j++)
                {
                    g[x.second[i]].push_back(x.second[j]);
                    g[x.second[j]].push_back(x.second[i]);
                }
            }
        }

        vector<int> q;
        vector<int> q2;
        q.push_back(0);
        v[0] = true;
        int r = 0;

        /* for(int i = 0; i < n; i++) {
            cout << i << ": ";
            for(auto &x : g[i]) cout << x << " ";
            cout << endl;
        }
        */

        while (q.size() != 0)
        {
            ++r;
            for (auto &i : q)
            {
                //      cout << i << " ";
                for (auto &j : g[i])
                {
                    if (!v[j])
                    {
                        v[j] = true;
                        q2.push_back(j);
                    }
                    if (j == n - 1)
                        return r;
                }
            }
            //   cout << endl;
            q = q2;
            q2.clear();
        }

        return 0;
    }
};