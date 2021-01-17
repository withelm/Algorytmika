class Solution
{
private:
    double calc(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        return (a[0] * (b[1] - c[1]) + b[0] * (c[1] - a[1]) + c[0] * (a[1] - b[1])) / 2.0;
    }

public:
    double largestTriangleArea(vector<vector<int>> &t)
    {
        double r = 0;
        for (auto &x : t)
            for (auto &y : t)
                for (auto &z : t)
                {
                    r = max(r, calc(x, y, z));
                }
        return r;
    }
};