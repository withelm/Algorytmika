class Solution
{
public:
    vector<int> sortedSquares(vector<int> &A)
    {
        for (vector<int>::iterator it = A.begin(); it != A.end(); it++)
        {
            *it = (*it) * (*it);
        }
        sort(A.begin(), A.end());
        return A;
    }
};