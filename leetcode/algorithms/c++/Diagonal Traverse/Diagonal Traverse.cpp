class Solution
{
private:
    vector<int> getData(int x, int y, vector<vector<int>> &matrix, int n, int m, int even)
    {
        vector<int> result;
        while (x < n && y >= 0)
        {
            result.push_back(matrix[x++][y--]);
        }
        if (even % 2 == 1)
            reverse(result.begin(), result.end());
        return result;
    }

public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return {};
        int m = matrix[0].size();

        vector<int> r;

        int x = 0, y = 0;
        int even = 1;
        for (int i = 0; i < m; i++)
        {
            vector<int> tmp;
            tmp = getData(x, y + i, matrix, n, m, even);
            for (auto &x : tmp)
                r.push_back(x);

            ++even;
        }
        for (int i = 1; i < n; i++)
        {

            vector<int> tmp;
            tmp = getData(x + i, m - 1, matrix, n, m, even);
            for (auto &x : tmp)
                r.push_back(x);
            ++even;
        }

        return r;
    }
};