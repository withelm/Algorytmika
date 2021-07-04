class Solution
{
private:
    priority_queue<int> q;

public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
    {
        int r = 0;
        int pos = 0;
        stations.push_back({target, 0});
        for (auto &item : stations)
        {
            if (item[0] - pos <= startFuel)
            {
                startFuel -= (item[0] - pos);
                q.push(item[1]);
            }
            else
            {

                while (!q.empty() && item[0] - pos > startFuel)
                {
                    startFuel += q.top();
                    ++r;
                    q.pop();
                }
                q.push(item[1]);
                startFuel -= (item[0] - pos);
                if (startFuel < 0)
                    return -1;
            }
            pos = item[0];
        }

        return r;
    }
};