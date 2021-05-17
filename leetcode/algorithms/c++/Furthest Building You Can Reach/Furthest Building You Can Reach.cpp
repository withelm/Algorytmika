class Solution
{
private:
    vector<int> diff;
    int n;
    int bricks;
    int ladders;

    bool check(int len)
    {
        vector<int> tmp;
        for (int i = 0; i < len; i++)
        {
            if (diff[i] != 0)
                tmp.push_back(diff[i]);
        }
        sort(tmp.begin(), tmp.end(), [](const int x, const int y) { return x > y; });

        int tmp_brick = bricks;
        int tmp_ladders = ladders;

        long long int sum = 0;
        for (auto &x : tmp)
            sum += x;

        int i = 0;
        while (i < n && sum > tmp_brick && tmp_ladders > 0)
        {
            --tmp_ladders;
            sum -= tmp[i];
            ++i;
        }

        return sum <= tmp_brick;
    }

public:
    int furthestBuilding(vector<int> &heights, int _bricks, int _ladders)
    {
        n = heights.size() - 1;
        bricks = _bricks;
        ladders = _ladders;

        for (int i = 1; i <= n; i++)
            diff.push_back(max(heights[i] - heights[i - 1], 0));

        int left = 0;
        int right = n + 1;
        int mid = (left + right) / 2;
        while (left < right)
        {
            mid = (left + right) / 2;
            if (check(mid))
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        vector<int> t;
        for (int i = -1; i < 1; i++)
        {
            t.push_back(left + i);
            t.push_back(right + i);
            t.push_back(mid + i);
        }

        sort(t.begin(), t.end(), [](int a, int b) { return a > b; });

        for (auto &x : t)
        {
            if (x >= 0 && x <= n)
            {
                if (check(x))
                    return x;
            }
        }

        return -1;
    }
};