class Solution
{
private:
    int n, m;
    int result = -1e9;

    void update(vector<int> &row, int k)
    {
        int sum = 0;
        set<int> srSum;

        srSum.insert(0);
        for (auto &x : row)
        {
            sum += x;
            auto item = srSum.lower_bound(sum - k);
            if (item != srSum.end())
                result = max(result, sum - *item);
            srSum.insert(sum);
        }
    }

public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k)
    {
        n = matrix.size();
        m = matrix[0].size();

        vector<int> row(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                row[j] = 0;

            for (int x = i; x < n; x++)
            {
                for (int j = 0; j < m; j++)
                    row[j] += matrix[x][j];
                update(row, k);
                if (result == k)
                    return k;
            }
        }

        return result;
    }
};