class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        int sum = 0;
        for (auto &x : nums)
            sum += x;
        if (sum % 2 != 0)
            return false;

        vector<bool> t(sum + 1, false);

        t[0] = true;

        for (auto &i : nums)
        {
            for (int j = sum; j >= 0; j--)
            {
                if (t[j] && j + i < sum + 1)
                {

                    t[j + i] = true;
                }
            }
        }

        return t[sum / 2];
    }
};