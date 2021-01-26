

class Solution
{
private:
    vector<vector<bool>> vis;
    vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int n, m;
    bool check(vector<vector<int>> &t, int k)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                vis[i][j] = false;
            }
        }

        deque<vector<int>> q;

        q.push_back({0, 0});

        vis[0][0] = true;
        while (!q.empty())
        {
            auto curr = q.front();
            for (auto &move : moves)
            {
                int x = curr[0] + move[0];
                int y = curr[1] + move[1];
                if (x < 0 || x >= n || y < 0 || y >= m)
                    continue;
                if (vis[x][y])
                    continue;
                if (abs(t[curr[0]][curr[1]] - t[x][y]) <= k)
                {
                    q.push_back({x, y});
                    vis[x][y] = true;
                }
            }
            q.pop_front();
        }
        return vis[n - 1][m - 1];
    }

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        n = heights.size();
        m = heights[0].size();
        vis.resize(n);
        for (int i = 0; i < n; i++)
            vis[i].resize(m);

        int left = 0;
        int right = 1e6;
        int mid;
        int r = 1e9;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (check(heights, mid))
            {
                r = min(r, mid);
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return r;
    }
};