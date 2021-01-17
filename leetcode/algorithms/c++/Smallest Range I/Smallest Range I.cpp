class Solution
{
public:
    int smallestRangeI(vector<int> &A, int K)
    {
        sort(A.begin(), A.end());
        int f = A[0];
        int n = A.size();
        int s = A[n - 1];
        if (s - f <= K)
            return 0;

        int r = s - f;
        r = min(r, max(0, s + K - f - K));
        r = min(r, max(0, s + K - f + K));
        r = min(r, max(0, s - K - f - K));
        r = min(r, max(0, s - K - f + K));
        return r;
    }
};