class Solution
{
private:
    int INF = 1e9;
    int check(int x, vector<int> &A, vector<int> &B)
    {
        int n = A.size();
        int r = 0;
        for (int i = 0; i < n; i++)
        {
            if (A[i] != x)
            {
                ++r;
                if (B[i] != x)
                    return INF;
            }
        }
        return r;
    }

public:
    int minDominoRotations(vector<int> &A, vector<int> &B)
    {
        int r = INF;
        for (int i = 1; i <= 6; i++)
        {
            r = min(r, check(i, A, B));
            r = min(r, check(i, B, A));
        }
        return r == INF ? -1 : r;
    }
};