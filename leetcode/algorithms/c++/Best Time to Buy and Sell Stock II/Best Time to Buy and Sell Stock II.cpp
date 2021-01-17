class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() < 2)
            return 0;
        int result = 0;
        int current = prices[0];
        for (int i = 0; i < prices.size(); i++)
        {
            if (current > prices[i])
            {
                current = prices[i];
                continue;
            }
            if (current < prices[i])
            {
                int j = i;
                while (j + 1 < prices.size() && prices[j] < prices[j + 1])
                    ++j;
                result += prices[j] - current;
                if (j + 1 < prices.size())
                    current = prices[j + 1];
                else
                    current = 1e9;
                i = j;
            }
        }
        result += max(0, prices.back() - current);
        return result;
    }
};