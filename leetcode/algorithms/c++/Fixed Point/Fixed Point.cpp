class Solution
{
public:
    int fixedPoint(vector<int> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            if (i == A[i])
                return i;
        }
        return -1;
    }
};