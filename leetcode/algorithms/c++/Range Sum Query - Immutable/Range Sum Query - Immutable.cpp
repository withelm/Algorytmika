class NumArray
{
private:
    vector<int> pref;

public:
    NumArray(vector<int> &nums)
    {
        pref.resize(nums.size());
        if (nums.size() == 0)
            return;
        pref[0] = nums[0];
        for (int i = 1; i < pref.size(); i++)
        {
            pref[i] = pref[i - 1] + nums[i];
        }
    }

    int sumRange(int i, int j)
    {
        if (i > 0)
            return pref[j] - pref[i - 1];
        return pref[j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */