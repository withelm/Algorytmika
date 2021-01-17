class Solution
{
private:
    map<int, int> getBase(vector<int> &t)
    {
        map<int, int> base;
        for (auto &x : t)
            ++base[x];
        return base;
    }

public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        auto base1 = getBase(nums1);
        auto base2 = getBase(nums2);

        vector<int> r;
        for (auto &x : base1)
        {
            for (int i = 0; i < min(x.second, base2[x.first]); i++)
            {
                r.push_back(x.first);
            }
        }
        return r;
    }
};