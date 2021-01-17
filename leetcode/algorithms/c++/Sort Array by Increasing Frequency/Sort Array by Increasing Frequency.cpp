map<int, int> base;

bool cmp(int a, int b)
{
    if (a == b)
        return false;
    if (base[a] == base[b])
        return a > b;
    return base[a] < base[b];
}

class Solution
{

public:
    vector<int> frequencySort(vector<int> &nums)
    {
        base.clear();
        for (auto &x : nums)
            ++base[x];
        sort(nums.begin(), nums.end(), cmp);
        return nums;
    }
};