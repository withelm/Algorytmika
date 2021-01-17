class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> n1, n2;
        for (auto &x : nums1)
            n1.insert(x);
        for (auto &x : nums2)
            n2.insert(x);

        map<int, int> base;
        for (auto &x : n1)
            ++base[x];
        for (auto &x : n2)
            ++base[x];

        vector<int> r;
        for (auto &x : base)
            if (x.second == 2)
                r.push_back(x.first);
        return r;
    }
};