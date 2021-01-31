class Solution
{
public:
    vector<int> processQueries(vector<int> &queries, int m)
    {
        vector<int> t(m, 0);
        vector<int> result;
        for (int i = 1; i <= m; i++)
            t[i - 1] = i;
        for (auto &x : queries)
        {
            int i = 0;
            while (t[i] != x)
                ++i;
            t.erase(t.begin() + i);
            t.insert(t.begin(), x);
            result.push_back(i);
        }
        return result;
    }
};