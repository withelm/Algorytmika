class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int m = flowerbed.size();
        int result = 0;
        for (int i = 0; i < m; i++)
        {
            if (flowerbed[i] == 1)
                continue;
            if (i - 1 >= 0 && i + 1 < m)
            {
                if (flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)
                {
                    ++result;
                    flowerbed[i] = 1;
                }
                continue;
            }
            if (i - 1 < 0 && i + 1 < m)
            {
                if (flowerbed[i + 1] == 0)
                {
                    ++result;
                    flowerbed[i] = 1;
                }
                continue;
            }
            if (i - 1 >= 0 && i + 1 >= m)
            {
                if (flowerbed[i - 1] == 0)
                {
                    ++result;
                    flowerbed[i] = 1;
                }
                continue;
            }
            if (i - 1 < 0 && i + 1 >= m)
            {
                ++result;
                flowerbed[i] = 1;
                continue;
            }
        }

        return n <= result;
    }
};