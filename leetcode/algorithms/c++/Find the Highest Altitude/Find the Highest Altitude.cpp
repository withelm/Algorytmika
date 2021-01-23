class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int r = 0;
        int hig = 0;
        for (auto &x : gain)
        {
            hig += x;
            r = max(r, hig);
        }
        return r;
    }
};