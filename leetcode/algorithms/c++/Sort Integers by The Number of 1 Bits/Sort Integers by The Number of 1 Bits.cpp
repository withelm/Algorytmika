class Solution
{
private:
    int calc(int x)
    {
        int r = 0;
        while (x > 0)
        {
            r += x % 2;
            x /= 2;
        }
        return r;
    }
    bool static cmp(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }

public:
    vector<int> sortByBits(vector<int> &arr)
    {
        vector<vector<int>> r;
        for (auto &x : arr)
        {
            r.push_back({x, calc(x)});
        }
        sort(r.begin(), r.end(), cmp);
        vector<int> result;
        for (auto &x : r)
        {
            result.push_back(x[0]);
        }
        return result;
    }
};