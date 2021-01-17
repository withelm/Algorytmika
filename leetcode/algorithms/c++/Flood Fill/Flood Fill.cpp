class Solution
{
private:
    vector<vector<int>> t;
    int n, m;
    void dfs(int x, int y, int old, int newc)
    {
        if (x < 0 || y < 0 || x >= n || y >= m)
            return;
        if (t[x][y] != old)
            return;

        t[x][y] = newc;
        dfs(x + 1, y, old, newc);
        dfs(x - 1, y, old, newc);
        dfs(x, y + 1, old, newc);
        dfs(x, y - 1, old, newc);
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        t = image;

        n = image.size();
        m = image[0].size();
        if (t[sr][sc] != newColor)
            dfs(sr, sc, t[sr][sc], newColor);

        return t;
    }
};