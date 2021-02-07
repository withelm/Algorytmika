class Solution
{
private:
    bool check(int index, vector<int> &nums, vector<int> &t)
    {
        for (int i = 0; i < t.size(); i++)
        {
            if (t[i] != nums[(index + i) % t.size()])
                return false;
        }
        return true;
    }

public:
    bool check(vector<int> &nums)
    {
        int n = nums.size();
        map<int, int> base;
        for (auto &x : nums)
            ++base[x];

        vector<int> t;
        for (auto &x : base)
        {
            for (int i = 0; i < x.second; i++)
                t.push_back(x.first);
        }

        int index = 0;
        while (nums[index] != t[0])
            ++index;

        for (int i = 0; i < n; i++)
        {
            if (nums[i] == t[0])
                if (check(i, nums, t))
                    return true;
        }
        return false;
    }
};