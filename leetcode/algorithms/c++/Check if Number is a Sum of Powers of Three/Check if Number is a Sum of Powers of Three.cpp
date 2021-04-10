class Solution
{
private:
    set<int> base;
    int MX;
    int LIMIT;

    int calc(int x)
    {
        int r = 0;
        int tree = 1;
        for (int i = 0; i < MX; i++)
        {
            if (x % 2 == 0)
            {
                r += tree;
            }
            x /= 2;
            tree *= 3;
        }
        return r;
    }

public:
    bool checkPowersOfThree(int n)
    {
        MX = (log10(n) / log10(3)) + 1;
        LIMIT = 1 << MX;

        for (int i = 0; i < LIMIT; i++)
        {
            base.insert(calc(i));
        }
        return base.find(n) != base.end();
    }
};