class Solution
{
private:
    int len(vector<int> x, vector<int> y)
    {
        return (y[1] - x[1]) * (y[1] - x[1]) + (y[0] - x[0]) * (y[0] - x[0]);
    }
    bool check(vector<int> a, vector<int> b, vector<int> c, vector<int> d)
    {
        vector<int> lens = {len(a, b), len(b, c), len(c, d), len(d, a)};
        vector<int> cross = {len(a, c), len(b, d)};

        if (lens[0] <= 0 || cross[0] <= 0)
            return false;
        for (int i = 0; i < 4; i++)
        {
            if (lens[i] != lens[(i + 1) % 4])
                return false;
        }
        return cross[0] == cross[1];
    }

public:
    bool validSquare(vector<int> &p1, vector<int> &p2, vector<int> &p3, vector<int> &p4)
    {
        vector<vector<int>> points = {p1, p2, p3, p4};
        sort(points.begin(), points.end());

        do
        {
            if (check(points[0], points[1], points[2], points[3]))
                return true;
        } while (std::next_permutation(points.begin(), points.end()));
        return false;
    }
};