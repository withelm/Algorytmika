class Solution
{
public:
    vector<int> sumEvenAfterQueries(vector<int> &A, vector<vector<int>> &queries)
    {
        vector<int> r;
        int tmp = 0;
        for (auto &x : A)
            if (x % 2 == 0)
                tmp += x;
        for (auto &x : queries)
        {
            if (A[x[1]] % 2 == 0)
                tmp -= A[x[1]];
            A[x[1]] += x[0];
            if (A[x[1]] % 2 == 0)
                tmp += A[x[1]];
            r.push_back(tmp);
        }
        return r;
    }
};