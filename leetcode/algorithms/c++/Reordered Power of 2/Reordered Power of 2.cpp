class Solution
{
private:
    set<vector<int>> base;
    long long int LIMIT = 1e9 * 10LL;

    vector<int> convert(int x)
    {
        vector<int> res;
        while (x > 0)
        {
            res.push_back(x % 10);
            x /= 10;
        }
        sort(res.begin(), res.end());
        return res;
    }

public:
    bool reorderedPowerOf2(int N)
    {
        for (long long int i = 1; i <= LIMIT; i *= 2)
        {
            base.insert(convert(i));
        }
        return base.find(convert(N)) != base.end();
    }
};