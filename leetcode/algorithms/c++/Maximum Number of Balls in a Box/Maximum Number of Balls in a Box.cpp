class Solution
{
private:
    int calc(int x)
    {
        int r = 0;
        while (x > 0)
        {
            r += x % 10;
            x /= 10;
        }
        return r;
    }

public:
    int countBalls(int lowLimit, int highLimit)
    {
        map<int, int> base;
        int r = 0;
        for (int i = lowLimit; i <= highLimit; i++)
        {
            r = max(r, ++base[calc(i)]);
        }
        return r;
    }
};