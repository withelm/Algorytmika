class Solution
{
private:
    int find_min(vector<int> &t, int begin)
    {
        int result = t[begin];
        for (int i = begin + 1; i < t.size(); i++)
        {
            if (result >= t[i])
                return t[i];
        }
        return 0;
    }

public:
    vector<int> finalPrices(vector<int> &prices)
    {
        vector<int> result;
        for (int i = 0; i < prices.size(); i++)
        {
            result.push_back(prices[i] - find_min(prices, i));
        }
        return result;
    }
};