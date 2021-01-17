class Solution
{

private:
    map<vector<int>, bool> base;

    bool check(vector<int> &p, int a, int b, int v1, int v2, int m)
    {
        cout << a << " " << b << " " << v1 << " " << v2 << " " << m << endl;
        if (a == b)
            return v1 < v2;

        if (base.find({a, b}) != base.find({a, b}))
            return base[{a, b}];

        if (m % 2 == 0)
        {
            auto a1 = check(p, a + 1, b, v1 + p[a], v2, m + 1);
            auto a2 = check(p, a, b - 1, v1 + p[b - 1], v2, m + 1);

            return base[{a, b}] = a1 || a2;
        }
        auto a1 = check(p, a + 1, b, v1, v2 + p[a], m + 1);
        auto a2 = check(p, a, b - 1, v1, v2 + p[b - 1], m + 1);
        return base[{a, b}] = a1 || a2;
    }

public:
    bool stoneGame(vector<int> &piles)
    {
        return true; //:'(
    }
};