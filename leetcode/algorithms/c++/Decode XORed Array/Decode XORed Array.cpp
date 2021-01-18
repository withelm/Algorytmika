class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> r = {first};
        for (auto &x : encoded)
        {
            r.push_back(r.back() ^ x);
        }
        return r;
    }
};