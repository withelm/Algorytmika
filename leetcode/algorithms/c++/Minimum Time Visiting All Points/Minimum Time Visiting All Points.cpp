class Solution
{

private:
    int mintTimeToVisit(vector<int> a, vector<int> b)
    {
        int x1 = min(a[0], b[0]);
        int y1 = min(a[1], b[1]);
        int x2 = max(a[0], b[0]);
        int y2 = max(a[1], b[1]);
        int h = abs(x2 - x1);
        int w = abs(y2 - y1);
        return max(h, w);
    }

public:
    int minTimeToVisitAllPoints(vector<vector<int>> &points)
    {
        int result = 0;
        for (int i = 1; i < points.size(); i++)
        {
            result += mintTimeToVisit(points[i - 1], points[i]);
        }
        return result;
    }
};