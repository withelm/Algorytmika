class Solution
{
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        for (auto &x : A)
            reverse(x.begin(), x.end());
        for (auto &i : A)
            for (auto &j : i)
                j = (j + 1) % 2;
        return A;
    }
};