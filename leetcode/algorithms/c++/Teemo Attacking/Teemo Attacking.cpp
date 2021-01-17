class Solution
{
public:
    int findPoisonedDuration(vector<int> &timeSeries, int duration)
    {
        if (timeSeries.size() == 0)
            return 0;
        sort(timeSeries.begin(), timeSeries.end());

        int result = 0;
        int i = 0;
        int n = timeSeries.size();

        int begin = timeSeries[i];
        int end = timeSeries[i] + duration;
        ++i;
        while (i < n)
        {
            if (timeSeries[i] <= end)
            {
                end = timeSeries[i] + duration;
            }
            else
            {
                result += end - begin;
                begin = timeSeries[i];
                end = timeSeries[i] + duration;
            }
            ++i;
        }

        return result + end - begin;
    }
};