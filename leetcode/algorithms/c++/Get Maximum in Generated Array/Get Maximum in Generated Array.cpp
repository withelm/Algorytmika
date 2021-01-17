class Solution
{
public:
    int getMaximumGenerated(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        vector<int> t;
        t.push_back(0);
        t.push_back(1);
        for (int i = 2; i <= n; i++)
        {
            if (i % 2 == 0)
                t.push_back(t[i / 2]);
            else
                t.push_back(t[i / 2] + t[(i / 2) + 1]);
        }
        return *max_element(t.begin(), t.end());
    }
};