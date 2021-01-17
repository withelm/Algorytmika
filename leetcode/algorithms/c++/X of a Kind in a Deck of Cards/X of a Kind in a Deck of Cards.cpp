class Solution
{
private:
    int gcd(int a, int b)
    {
        if (b != 0)
            return gcd(b, a % b);
        return a;
    }

public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        map<int, int> base;
        for (auto &x : deck)
        {
            ++base[x];
        }
        int min_val = 1e4 + 100;
        for (auto &x : base)
        {
            if (x.second == 1)
                return false;
            min_val = min(min_val, x.second);
        }

        for (auto &x : base)
        {
            min_val = gcd(min_val, x.second);
        }
        return min_val != 1;
    }
};