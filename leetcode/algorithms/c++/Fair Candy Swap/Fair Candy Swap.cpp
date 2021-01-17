class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {

        int cur = 0;
        int sumA = 0;
        for (auto &x : A)
            cur += x;
        sumA = cur;

        map<int, int> base;
        for (auto &x : B)
        {
            ++base[x];
            cur += x;
        }

        cur /= 2;

        for (auto &x : A)
        {
            if (base[(cur - (sumA - x))] != 0)
            {
                return {x, (cur - (sumA - x))};
            }
        }
        return {};
    }
};