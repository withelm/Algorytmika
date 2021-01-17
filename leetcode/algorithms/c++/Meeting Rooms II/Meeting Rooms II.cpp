class pkt
{
public:
    int x, v;
};

bool cmp(pkt &x, pkt &y)
{
    return x.x < y.x;
}

class Solution
{
public:
    int minMeetingRooms(vector<vector<int>> &intervals)
    {
        vector<pkt> t;
        for (auto &x : intervals)
        {
            pkt tmp;
            tmp.x = x[0];
            tmp.v = 1;
            t.push_back(tmp);
            tmp.x = x[1];
            tmp.v = -1;
            t.push_back(tmp);
        }
        sort(t.begin(), t.end(), cmp);
        int r = 0;
        int v = 0;
        int index = 0;
        while (index < t.size())
        {
            int curr = t[index].x;
            while (index < t.size() && curr == t[index].x)
            {
                v += t[index].v;
                ++index;
            }
            r = max(r, v);
        }
        return r;
    }
};