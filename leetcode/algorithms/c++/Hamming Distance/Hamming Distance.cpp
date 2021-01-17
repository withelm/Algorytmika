class Solution
{
private:
    vector<int> getBinary(int n)
    {
        vector<int> result;
        int i = 32;
        while (i--)
        {
            result.push_back(n % 2);
            n /= 2;
        }
        return result;
    }

public:
    int hammingDistance(int x, int y)
    {
        auto xb = getBinary(x);
        auto yb = getBinary(y);
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            if (xb[i] != yb[i])
                ++result;
        }
        return result;
    }
};