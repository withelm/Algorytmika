class Solution
{
private:
    int MX = (2000 + 10) / 2;

public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        vector<int> v(2 * MX, 0);
        for (auto &x : arr)
        {
            ++v[x + MX];
        }
        vector<int> t(MX, 0);
        for (int i = 0; i < 2 * MX; i++)
        {
            if (v[i] != 0 && t[v[i]] > 0)
                return false;
            t[v[i]] = 1;
        }
        return true;
    }
};