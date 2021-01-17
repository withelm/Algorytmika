class Solution
{
private:
    vector<vector<int>> base;
    int _k;
    set<int> check(int i, int j)
    {
        //cout << "> " << i << " " << j << endl;
        set<int> r;
        for (int ii = 0; ii < 255; ii++)
        {
            int calc = base[j][ii] - base[i][ii];
            //  cout << ">> " << i << " " << j << " " << calc << endl;
            if (calc == 0)
                continue;
            if (calc < _k)
                r.insert(ii);
        }
        return r;
    }
    string _s;
    int result = 0;

    void dfs(int start, int end)
    {
        if (end > _s.size())
            return;
        if (start >= end)
            return;
        auto toCheck = check(start, end);
        if (toCheck.size() == 0)
        {
            result = max(result, end - start);
            return;
        }

        int s = start;
        int e = start;
        while (s < end && e < end)
        {
            while (s < end && toCheck.find(_s[s]) != toCheck.end())
            {
                ++s;
            }
            e = s;
            while (e < end && toCheck.find(_s[e]) == toCheck.end())
            {
                ++e;
            }
            dfs(s, e);
            ++s;
        }
    }

public:
    int longestSubstring(string s, int k)
    {
        int n = s.size();
        if (n < k)
            return 0;
        _k = k;
        base.resize(n + 1);
        for (auto &x : base)
        {
            x.resize(255);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < 255; j++)
            {
                base[i][j] = base[i - 1][j];
            }
            ++base[i][s[i - 1]];
        }
        _s = s;

        dfs(0, n);

        return result;
    }
};