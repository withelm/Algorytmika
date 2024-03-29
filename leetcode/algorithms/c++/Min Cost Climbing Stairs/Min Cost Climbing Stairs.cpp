class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        vector<int> t(n, 0);

        t[0] = cost[0];
        t[1] = cost[1];
        for (int i = 2; i < n; i++)
        {
            t[i] = min(t[i - 2], t[i - 1]) + cost[i];
        }

        return min(t[n - 1], t[n - 2]);
    }
};