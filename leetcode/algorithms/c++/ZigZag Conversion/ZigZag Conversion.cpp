class Solution
{
private:
    vector<vector<int>> moves = {{1, 0}, {-1, 1}};
    int direct = 0;

public:
    string convert(string s, int n)
    {
        if (n == 1)
            return s;
        int m = s.size();
        vector<vector<char>> t(n, vector<char>(m, 0));
        int index = 0;

        int x = 0, y = 0;
        while (index < s.size())
        {

            t[x][y] = s[index];
            ++index;
            int x_tmp = x + moves[direct][0];
            int y_tmp = y + moves[direct][1];
            if (x_tmp < 0 || x_tmp >= n || y_tmp < 0 || y_tmp >= m)
            {
                direct = (direct + 1) % 2;
            }
            x += moves[direct][0];
            y += moves[direct][1];
        }

        string r = "";
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (t[i][j] != 0)
                    r += t[i][j];
            }
        }

        return r;
    }
};