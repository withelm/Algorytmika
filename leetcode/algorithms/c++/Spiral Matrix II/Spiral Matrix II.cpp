class Solution
{
private:
    vector<vector<int>> moves = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

    bool check(int x, int y, vector<int> &mv, vector<vector<int>> &r)
    {
        x += mv[0];
        y += mv[1];
        int n = r.size();
        if (x < 0 || x >= n || y < 0 || y >= n)
            return false;
        return r[x][y] == -1;
    }

public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> r(n, vector<int>(n, -1));

        int val = 1;
        int x = 0;
        int y = -1;

        while (val <= n * n)
        {
            for (auto &i : moves)
            {
                while (check(x, y, i, r))
                {
                    x += i[0];
                    y += i[1];
                    //  cout << x << " " << y << endl;
                    r[x][y] = val++;
                }
            }
        }

        return r;
    }
};