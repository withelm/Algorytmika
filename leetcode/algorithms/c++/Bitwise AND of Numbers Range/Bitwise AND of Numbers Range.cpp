class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int r = n;
        while (m < r)
        {
            r &= r - 1;
        }
        return r & m;
    }
};