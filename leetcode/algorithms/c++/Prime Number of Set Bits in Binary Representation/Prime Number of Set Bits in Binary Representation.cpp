class Solution
{
private:
    vector<int> prime = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0};
    //   0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20
    int calc(int x)
    {
        int r = 0;
        while (x > 0)
        {
            r += x % 2;
            x /= 2;
        }
        return r;
    }

public:
    int countPrimeSetBits(int L, int R)
    {
        int r = 0;
        for (int i = L; i <= R; i++)
        {
            r += prime[calc(i)];
        }
        return r;
    }
};