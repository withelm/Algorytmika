class Point
{
public:
    int val, index;
};

Point min(Point &x, Point y)
{
    if (x.val == y.val)
    {
        if (x.index < y.index)
        {
            return x;
        }
        else
        {
            return y;
        }
    }
    if (x.val < y.val)
        return x;
    return y;
}

class Solution
{
private:
    vector<Point> q;
    int SIZE = 1 << 17;
    int FULL_SIZE = SIZE << 1;
    int INF = 1e9 + 1e9;
    int n;

    void add(int val, int index)
    {
        int i = index + SIZE;
        Point t;
        t.val = val;
        t.index = index;

        q[i] = t;
        i /= 2;

        while (i > 0)
        {
            q[i] = min(q[i * 2], q[i * 2 + 1]);
            i /= 2;
        }
    }

    Point query(int v, int L, int R, int a, int b)
    {

        if (L == a && R == b)
        {
            return q[v];
        }

        int mid = (a + b - 1) / 2;
        Point res;
        res.val = res.index = INF;
        if (R <= mid)
        {
            res = min(res, query(2 * v, L, R, a, mid));
        }
        else if (L > mid)
        {
            res = min(res, query(2 * v + 1, L, R, mid + 1, b));
        }
        else
        {
            res = min(res, query(2 * v, L, mid, a, mid));
            res = min(res, query(2 * v + 1, mid + 1, R, mid + 1, b));
        }
        return res;
    }

public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        q.resize(FULL_SIZE);
        for (int i = 0; i < FULL_SIZE; i++)
            q[i].val = q[i].index = INF;

        n = nums.size();

        for (int i = 0; i < n; i++)
            add(nums[i], i);

        int curr_index = 0;
        vector<int> r;
        while (k--)
        {
            auto tmp = query(1, curr_index, n - k - 1, 0, SIZE);
            r.push_back(tmp.val);
            curr_index = tmp.index + 1;
        }

        return r;
    }
};