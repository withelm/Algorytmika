class Solution
{
public:
    int brokenCalc(int X, int Y)
    {
        if (X >= Y)
            return X - Y;
        int r = 0;
        while (X < Y)
        {
            Y = (Y % 2 == 0) ? Y / 2 : Y + 1;
            ++r;
        }
        return r + X - Y;
    }
};