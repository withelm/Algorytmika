class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {

        int n = prices.size();
        if (n == 0)
            return 0;

        vector<int> prefix(n);
        vector<int> sufix(n);

        int min_val = prices[0];
        int part_result = 0;

        for (int i = 0; i < n; i++)
        {
            min_val = min(min_val, prices[i]);
            part_result = max(prices[i] - min_val, part_result);
            prefix[i] = part_result;
        }
        int max_val = prices[n - 1];
        part_result = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            max_val = max(max_val, prices[i]);
            part_result = max(max_val - prices[i], part_result);
            sufix[i] = part_result;
        }
        int result = max(prefix[0], prefix[n - 1]);
        for (int i = 1; i < n; i++)
        {
            result = max(result, prefix[i - 1] + sufix[i]);
        }

        return result;
    }
};