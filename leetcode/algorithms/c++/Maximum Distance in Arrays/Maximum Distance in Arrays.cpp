class pkt
{
public:
    vector<int> k;
    int index;
};

bool cmp(pkt &a, pkt &b)
{
    return *a.k.begin() < *b.k.begin();
}
bool cmp2(pkt &a, pkt &b)
{
    return a.k.back() > b.k.back();
}

class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int n = arrays.size();

        vector<pkt> x;
        vector<pkt> y;
        for (int i = 0; i < n; i++)
        {
            pkt tmp;
            tmp.k = arrays[i];
            tmp.index = i;
            x.push_back(tmp);
            y.push_back(tmp);
        }

        sort(x.begin(), x.end(), cmp);
        sort(y.begin(), y.end(), cmp2);

        if (x[0].index != y[0].index)
            return abs(x[0].k[0] - y[0].k.back());
        return max(abs(x[1].k[0] - y[0].k.back()), abs(x[0].k[0] - y[1].k.back()));
    }
};