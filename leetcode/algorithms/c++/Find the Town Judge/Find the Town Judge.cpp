class Solution
{
public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        map<int, int> to, from;
        for (auto &x : trust)
        {
            ++to[x[1]];
            ++from[x[0]];
        }
        for (int i = 1; i <= N; i++)
        {
            if (from[i] == 0 && to[i] == N - 1)
                return i;
        }
        return -1;
    }
};