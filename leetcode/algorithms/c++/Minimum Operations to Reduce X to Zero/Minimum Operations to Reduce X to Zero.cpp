class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int n = nums.size();
        vector<int> pref(n, 0);
        vector<int> suf(n, 0);
        pref[0] = nums[0];
        suf[n - 1] = nums[n - 1];

        if (nums[0] > x || nums[n - 1] > x)
            return -1;

        for (int i = 1; i < n; i++)
            pref[i] = pref[i - 1] + nums[i];
        for (int i = n - 2; i >= 0; i--)
            suf[i] = suf[i + 1] + nums[i];

        int r = n + 10;
        int begin_index = 0;
        while (begin_index < n && pref[begin_index] < x)
            ++begin_index;

        for (int i = n - 1; i >= 0; i--)
        {
            if (suf[i] == x)
                r = min(r, n - i);
        }

        if (begin_index >= n)
            return -1;

        int end_index = n - 1;
        while (begin_index >= 0)
        {
            if (pref[begin_index] == x)
            {
                r = min(r, begin_index + 1);
                --begin_index;
                continue;
            }
            int curr = x - pref[begin_index];
            while (end_index >= 0 && suf[end_index] < curr)
            {
                --end_index;
            }
            if (suf[end_index] == curr)
            {

                r = min(r, begin_index + 1 + (n - end_index));
            }
            --begin_index;
        }
        return r > n ? -1 : r;
    }
};