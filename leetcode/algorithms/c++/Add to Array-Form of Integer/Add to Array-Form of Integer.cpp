class Solution
{
public:
    vector<int> addToArrayForm(vector<int> &A, int K)
    {
        vector<int> result;
        vector<int> B;
        int tmp = 0;

        if (K == 0)
            B = {0};
        while (K > 0)
        {
            B.push_back(K % 10);
            K /= 10;
        }

        reverse(A.begin(), A.end());

        int n = B.size();
        int m = A.size();
        for (int i = 0; i < min(n, m); i++)
        {
            tmp += A[i] + B[i];
            result.push_back(tmp % 10);
            tmp /= 10;
        }
        for (int i = min(n, m); i < max(n, m); i++)
        {
            if (n > m)
                tmp += B[i];
            else
                tmp += A[i];
            result.push_back(tmp % 10);
            tmp /= 10;
        }
        if (tmp > 0)
            result.push_back(tmp);

        reverse(result.begin(), result.end());
        return result;
    }
};