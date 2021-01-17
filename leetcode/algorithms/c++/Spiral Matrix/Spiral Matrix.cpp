class Solution
{
private:
    int INF = -1e9;
    vector<vector<int>> move = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dir;

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        if (n == 0)
            return {};
        int m = matrix[0].size();
        dir = 0;

        int x = 0;
        int y = 0;
        vector<int> r;
        while (r.size() < n * m)
        {
            //  cout <<"Start> " << x << " " << y << " " << matrix[x][y] << endl;
            while (x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] != INF)
            {
                //  cout << x << " " << y << " " << matrix[x][y]<< endl;
                r.push_back(matrix[x][y]);
                matrix[x][y] = INF;
                x += move[dir][0];
                y += move[dir][1];
            }
            x -= move[dir][0];
            y -= move[dir][1];
            dir = (dir + 1) % 4;
            x += move[dir][0];
            y += move[dir][1];
        }
        return r;
    }
};