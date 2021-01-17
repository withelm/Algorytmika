class Solution
{
public:
    int twoSumLessThanK(vector<int> &A, int K)
    {
        int r = -1;
        int n = A.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (A[i] + A[j] < K)
                    r = max(r, A[i] + A[j]);
            }
        }
        return r;
    }
};