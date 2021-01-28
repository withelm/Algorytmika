class Solution
{
public:
    int minPartitions(string n)
    {
        int r = 0;
        for (auto &x : n)
            r = max(r, x - '0');
        return r;
    }
};