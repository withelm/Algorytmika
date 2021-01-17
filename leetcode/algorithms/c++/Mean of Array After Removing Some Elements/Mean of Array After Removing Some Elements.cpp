class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();

        int skip = ((5 * n) / 100) + (5 * n % 100 != 0);

        double sum = 0.0;
        int cnt = 0;
        for (int i = skip; i < n - skip; i++)
        {
            sum += arr[i];
            cnt += 1;
        }
        return sum / cnt;
    }
};