class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        int n = nums.size();
        map<int, string> base;
        for (auto &x : nums)
            base[x] = "";
        int rank = n;
        for (auto &x : base)
        {
            switch (rank)
            {
            case 1:
                x.second = "Gold Medal";
                break;
            case 2:
                x.second = "Silver Medal";
                break;
            case 3:
                x.second = "Bronze Medal";
                break;
            default:
                x.second = to_string(rank);
            }

            --rank;
        }

        vector<string> r;
        for (auto &x : nums)
        {
            r.push_back(base[x]);
        }
        return r;
    }
};