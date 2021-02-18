class Solution
{
private:
    int calc(int n)
    {
        return n * (n - 1) / 2;
    }

public:
    int numberOfArithmeticSlices(vector<int> &A)
    {
        int r = 0;
        int n = A.size();
        if (n < 3)
            return 0;
        int begin = 0;
        int end = 1;
        int diff = A[1] - A[0];
        for (int i = 2; i < n; i++)
        {
            if (diff == A[i] - A[end])
            {
                ++end;
            }
            else
            {
                if (end - begin > 1)
                    r += calc(end - begin);
                end = i;
                begin = i - 1;
                diff = A[end] - A[begin];
            }
        }
        if (end - begin > 1)
            r += calc(end - begin);
        return r;
    }
};