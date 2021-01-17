class Solution
{
public:
    int repeatedNTimes(vector<int> &A)
    {
        map<int, int> base;
        int n = A.size() / 2;
        for (auto &x : A)
        {
            ++base[x];
            if (base[x] == n)
                return x;
        }
        return -1;
    }
};