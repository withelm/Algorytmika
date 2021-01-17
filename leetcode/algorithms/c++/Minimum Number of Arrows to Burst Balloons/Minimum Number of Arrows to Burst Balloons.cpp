class pkt
{
public:
    int x, y;
    bool vis;
};

bool cmp(pkt &a, pkt &b)
{
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

class Solution
{
private:
    vector<pkt> t;

public:
    int findMinArrowShots(vector<vector<int>> &points)
    {

        if (points.size() == 0)
            return 0;

        for (auto &x : points)
        {
            pkt tmp;
            tmp.x = x[0];
            tmp.y = x[1];
            tmp.vis = true;
            t.push_back(tmp);
        }
        sort(t.begin(), t.end(), cmp);

        int result = 0;
        int sum = -1;
        int i = 0;
        int n = t.size();
        int x = -1, y = -1;
        while (i < n)
        {
            if (sum == -1)
            {
                sum = 1;
                x = t[i].x;
                y = t[i].y;
                ++i;
                continue;
            }
            //      cout << x << " " << y << endl;
            //   cout << i << " " << t[i].x << " " << t[i].y << endl;
            if (x <= t[i].x && y >= t[i].x)
            {
                x = max(x, t[i].x);
                y = min(y, t[i].y);
            }
            else
            {
                result += 1;
                sum = 1;
                x = t[i].x;
                y = t[i].y;
            }
            ++i;
        }
        return result + 1;
    }
};