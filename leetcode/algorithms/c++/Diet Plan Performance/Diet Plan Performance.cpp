class Solution
{
public:
    int dietPlanPerformance(vector<int> &calories, int k, int lower, int upper)
    {
        int sum = 0;
        int n = calories.size();
        int res = 0;
        for (int i = 0; i < k; i++)
        {
            sum += calories[i];
        }
        if (sum > upper)
            ++res;
        if (sum < lower)
            --res;
        for (int i = k; i < n; i++)
        {
            sum = sum + calories[i] - calories[i - k];
            if (sum > upper)
                ++res;
            if (sum < lower)
                --res;
        }
        return res;
    }
};