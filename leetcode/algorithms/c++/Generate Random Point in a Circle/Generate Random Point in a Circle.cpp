class Solution
{
private:
    double r, x, y;

public:
    Solution(double radius, double x_center, double y_center)
    {
        r = radius;
        x = x_center;
        y = y_center;
    }

    vector<double> randPoint()
    {
        while (true)
        {
            double a = (double)rand() / RAND_MAX * (r * 2) + x - r;
            double b = (double)rand() / RAND_MAX * (r * 2) + y - r;
            if (pow(a - x, 2) + pow(b - y, 2) <= r * r)
                return {a, b};
        }
        return {-1, -1};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */