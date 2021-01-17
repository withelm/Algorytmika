class Solution
{
public:
    vector<vector<int>> removeInterval(vector<vector<int>> &intervals, vector<int> &toBeRemoved)
    {
        vector<vector<int>> r;
        for (auto &x : intervals)
        {

            if (x[0] <= toBeRemoved[0] && x[1] >= toBeRemoved[1])
            {
                if (x[0] != toBeRemoved[0])
                    r.push_back({x[0], toBeRemoved[0]});
                if (toBeRemoved[1] != x[1])
                    r.push_back({toBeRemoved[1], x[1]});
                continue;
            }

            if (x[1] <= toBeRemoved[0])
            {
                r.push_back(x);
                continue;
            }
            if (x[1] >= toBeRemoved[0] && x[0] <= toBeRemoved[0])
            {
                x[1] = toBeRemoved[0];
                if (x[0] != x[1])
                    r.push_back(x);
                continue;
            }
            if (x[0] > toBeRemoved[0] && x[1] < toBeRemoved[1])
            {
                continue;
            }
            if (x[0] <= toBeRemoved[1] && x[1] >= toBeRemoved[1])
            {
                x[0] = toBeRemoved[1];
                if (x[0] != x[1])
                    r.push_back(x);
                continue;
            }
            if (x[0] > toBeRemoved[1])
            {
                r.push_back(x);
                continue;
            }
        }
        return r;
    }
};