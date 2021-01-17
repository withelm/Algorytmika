class Solution
{
private:
    int next(int x)
    {
        int result = 0;
        while (x > 0)
        {
            result += (x % 10) * (x % 10);
            x /= 10;
        }
        return result;
    }

public:
    bool isHappy(int n)
    {
        set<int> vis;
        while (vis.find(n) == vis.end())
        {
            vis.insert(n);
            n = next(n);
        }
        return n == 1;
    }
};