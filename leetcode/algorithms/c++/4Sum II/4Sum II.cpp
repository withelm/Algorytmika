class Solution
{
private:
    map<int, int> base;

public:
    int fourSumCount(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D)
    {
        for (auto &i : A)
        {
            for (auto &j : B)
            {
                ++base[i + j];
            }
        }
        int r = 0;
        for (auto &i : C)
        {
            for (auto &j : D)
            {
                r += base[-(i + j)];
            }
        }
        return r;
    }
};