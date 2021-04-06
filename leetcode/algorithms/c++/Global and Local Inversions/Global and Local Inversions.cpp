class Solution
{
public:
    bool isIdealPermutation(vector<int> &A)
    {
        int local = 0;
        int n = A.size();
        for (int i = 0; i < n - 1; i++)
        {
            local += A[i] > A[i + 1];
        }

        int global = 0;
        for (auto &x : A)
            x = -x;

        set<int> base;
        for (int i = 0; i < n; i++)
        {
            base.insert(A[i]);
            for (auto &x : base)
            {
                if (x < A[i])
                {
                    ++global;
                }
                else
                {
                    break;
                }
            }
            if (global > local)
                return false;
        }
        return global == local;
    }
};