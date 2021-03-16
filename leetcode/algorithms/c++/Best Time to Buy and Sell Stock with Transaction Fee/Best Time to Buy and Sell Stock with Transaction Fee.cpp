class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        int res = 0;
        int tmp = -prices[0];
        for (int i = 1; i < prices.size(); i++)
        {
            res = max(res, tmp + prices[i] - fee);
            tmp = max(tmp, res - prices[i]);
        }
        return res;
    }
};