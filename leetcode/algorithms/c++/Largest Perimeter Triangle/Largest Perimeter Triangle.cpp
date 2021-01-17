class Solution
{
public:
    int largestPerimeter(vector<int> &A)
    {
        sort(A.begin(), A.end());
        int r = 0;
        int n = A.size();
        for (int i = 0; i + 2 < n; i++)
        {
            if (A[i] + A[i + 1] > A[i + 2])
            {
                //cout << A[i] << " " << A[i+1] << " " << A[i+2] << endl;
                r = A[i] + A[i + 1] + A[i + 2];
            }
        }
        return r;
    }
};