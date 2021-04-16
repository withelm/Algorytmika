class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> r;
        int end = k + 1;
        int begin = 1;
        while (begin < end)
        {
            r.push_back(begin);
            r.push_back(end);
            ++begin;
            --end;
        }
        if (begin == end)
        {
            r.push_back(begin);
        }
        for (int i = k + 2; i <= n; i++)
            r.push_back(i);
        return r;
    }
};