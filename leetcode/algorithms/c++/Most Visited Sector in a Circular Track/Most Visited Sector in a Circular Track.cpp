class Solution
{
public:
    vector<int> mostVisited(int n, vector<int> &rounds)
    {
        map<int, int> base;
        int m = rounds.size();
        for (int i = 0; i < m; i++)
            --rounds[i];

        for (int i = 1; i < m; i++)
        {

            for (int j = rounds[i - 1]; j < rounds[i] + n; j++)
            {
                ++base[j % n];
            }
        }
        ++base[rounds.back()];
        int maxVal = -1;
        for (auto &x : base)
        {

            maxVal = max(x.second, maxVal);
        }

        vector<int> r;
        for (auto &x : base)
            if (x.second == maxVal)
                r.push_back(x.first + 1);
        return r;
    }
};