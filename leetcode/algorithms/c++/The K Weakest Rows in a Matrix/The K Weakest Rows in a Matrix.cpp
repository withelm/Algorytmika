class Solution
{
private:
    bool static compareInterval(vector<int> &a, vector<int> &b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        return a[1] < b[1];
    }

public:
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k)
    {
        vector<vector<int>> r;
        for (int i = 0; i < mat.size(); i++)
        {
            int c = 0;
            for (int j = 0; j < mat[i].size(); j++)
            {
                if (mat[i][j] == 1)
                {
                    ++c;
                }
            }
            r.push_back({i, c});
        }
        sort(r.begin(), r.end(), compareInterval);
        vector<int> result;
        int index = 0;
        while (k--)
        {
            result.push_back(r[index][0]);
            ++index;
        }
        return result;
    }
};