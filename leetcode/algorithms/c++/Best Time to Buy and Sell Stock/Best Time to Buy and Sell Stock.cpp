class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int minimum = prices[0];
        int result = 0;
        for (auto &x : prices)
        {
            minimum = min(minimum, x);
            result = max(result, x - minimum);
        }
        return result;
    }
};