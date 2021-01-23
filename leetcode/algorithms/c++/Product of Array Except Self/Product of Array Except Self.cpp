class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<long long int> pref(n, 1);
        vector<long long int> suf(n, 1);

        for (int i = 0; i < n; i++)
        {
            if (i - 1 >= 0)
                pref[i] = pref[i - 1] * nums[i];
            else
                pref[i] *= nums[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            if (i + 1 < n)
                suf[i] = suf[i + 1] * nums[i];
            else
                suf[i] *= nums[i];
        }

        vector<int> r(n, 0);
        r[0] = suf[1];
        r[n - 1] = pref[n - 2];
        for (int i = 1; i < n - 1; i++)
        {
            r[i] = pref[i - 1] * suf[i + 1];
        }
        return r;
    }
};