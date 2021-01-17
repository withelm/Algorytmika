class Solution
{
private:
    bool det(vector<int> &a, vector<int> &b, vector<int> &c)
    {
        int p = a[1] * b[0] + b[1] * c[0] + c[1] * a[0] -
                c[1] * b[0] - a[1] * c[0] - b[1] * a[0];

        return p != 0;
    }

public:
    bool isBoomerang(vector<vector<int>> &points)
    {

        return det(points[0], points[1], points[2]);
    }
};