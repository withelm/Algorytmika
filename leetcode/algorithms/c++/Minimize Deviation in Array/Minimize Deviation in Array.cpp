

class Solution
{
private:
    int INF = 1e9 + 1e9;

public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> q;
        int min_val = INF;
        for (auto &x : nums)
        {
            if (x % 2 == 0)
            {
                q.push(x);
                min_val = min(min_val, x);
            }
            else
            {
                q.push(x * 2);
                min_val = min(min_val, x * 2);
            }
        }
        int r = INF;
        auto curr = q.top();
        while (!q.empty() && curr % 2 == 0)
        {
            q.pop();
            r = min(r, curr - min_val);
            if (curr % 2 == 0)
            {
                q.push(curr / 2);
                min_val = min(min_val, curr / 2);
            }
            curr = q.top();
        }
        return min(r, curr - min_val);
    }
};