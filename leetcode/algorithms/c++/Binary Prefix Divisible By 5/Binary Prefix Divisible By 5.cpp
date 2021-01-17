class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &A)
    {

        vector<bool> r;
        int val = 0;

        for (auto &x : A)
        {
            val *= 2;
            val += x;
            val %= 10;
            r.push_back(val % 5 == 0);
        }
        return r;
    }
};