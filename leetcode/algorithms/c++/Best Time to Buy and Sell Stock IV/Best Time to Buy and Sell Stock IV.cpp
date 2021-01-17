class Solution
{
private:
    int INF = -1e9;

public:
    int maxProfit(int k, vector<int> &prices)
    {

        int n = prices.size();

        if (k == 0 || n < 2)
            return 0;

        if (k >= n)
        {
            int r = 0;
            for (int i = 1; i < n; i++)
            {
                r += max(0, prices[i] - prices[i - 1]);
            }
            return r;
        }

        vector<vector<vector<int>>> t(n, vector<vector<int>>(k + 1, vector<int>(2, INF)));

        t[0][0][0] = 0;
        t[0][1][1] = -prices[0];
        int r = INF;
        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j <= k; j++)
            {
                t[i][j][0] = max(t[i - 1][j][0], t[i - 1][j][1] + prices[i]);
                t[i][j][1] = max(t[i - 1][j][1], j > 0 ? t[i - 1][j - 1][0] - prices[i] : INF);

                if (i == n - 1)
                    r = max(r, t[i][j][0]);
            }
        }

        return r;
    }
};