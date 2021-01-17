class Solution
{
public:
    int maxCoins(vector<int> &piles)
    {
        sort(piles.begin(), piles.end());
        int result = 0;
        int n = piles.size();
        int index = n - 2;
        for (int i = 0; i < n / 3; i++)
        {
            result += piles[index];
            index -= 2;
        }
        return result;
    }
};