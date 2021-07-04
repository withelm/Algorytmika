class Solution
{

private:
    int MX = 1e6;
    int HALF = MX / 2;
    vector<int> t;
    int n;
    vector<int> nums;

    int magic(int x)
    {
        return ((x ^ (x - 1)) + 1) / 2;
    }

public:
    vector<int> countSmaller(vector<int> &_nums)
    {
        n = MX;
        nums = _nums;
        t.resize(n);
        for (int i = 0; i < MX; i++)
            t[i] = 0;

        vector<int> r(_nums.size(), 0);

        for (int i = _nums.size() - 1; i >= 0; i--)
        {
            r[i] = sum(_nums[i] + HALF - 1);
            insert(_nums[i] + HALF, 1);
        }
        return r;
    }

    void insert(int index, int val)
    {
        while (index < n)
        {
            t[index] += val;
            index += magic(index);
        }
    }

    int sum(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += t[x];
            x -= magic(x);
        }
        return res;
    }
};