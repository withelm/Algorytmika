class Solution
{
public:
    int findNumberOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
            return 0;

        vector<int> l(n, 0);
        vector<int> c(n, 1);
        int max_l = 0;
        for (int j = 0; j < n; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (nums[i] < nums[j])
                {
                    if (l[i] >= l[j])
                    {
                        c[j] = c[i];
                        l[j] = l[i] + 1;
                    }
                    else if (l[i] + 1 == l[j])
                    {
                        c[j] += c[i];
                    }
                }
            }
        }
        for (int i = 0; i < n; i++)
            max_l = max(max_l, l[i]);
        int r = 0;
        cout << max_l << endl;
        for (int i = 0; i < n; i++)
        {
            if (l[i] == max_l)
                r += c[i];
        }
        return r;
    }
};