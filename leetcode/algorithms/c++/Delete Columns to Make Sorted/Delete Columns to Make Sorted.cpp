class Solution
{
public:
    int minDeletionSize(vector<string> &A)
    {
        int result = 0;
        int n = A[0].size();
        for (int i = 0; i < n; i++)
        {
            char last = 0;
            for (auto &x : A)
            {
                if (last > x[i])
                {
                    ++result;
                    break;
                }
                last = x[i];
            }
        }
        return result;
    }
};