class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        vector<vector<int>> base;
        bool isNew = true;
        for (auto &x : nums)
        {
            if (x == 0)
            {
                isNew = true;
            }
            else
            {
                if (isNew)
                {
                    base.push_back({x});
                    isNew = false;
                }
                else
                {
                    base.back().push_back(x);
                }
            }
        }
        int result = 0;
        for (auto &row : base)
        {
            if (row.size() == 1)
            {
                result = max(result, row[0]);
                continue;
            }

            int result_tmp = 1;
            vector<int> pref(row.size());
            vector<int> suf(row.size());
            int n = row.size();
            for (int i = 0; i < n; i++)
            {
                result_tmp *= row[i];
                pref[i] = result_tmp;
            }
            result_tmp = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                result_tmp *= row[i];
                suf[i] = result_tmp;
            }
            result = max(result, result_tmp);
            if (result_tmp > 0)
                continue;
            for (int i = 0; i < n; i++)
            {
                if (row[i] < 0)
                {
                    result = max(result, result_tmp / pref[i]);
                    result = max(result, result_tmp / suf[i]);
                }
            }
        }

        return result;
    }
};