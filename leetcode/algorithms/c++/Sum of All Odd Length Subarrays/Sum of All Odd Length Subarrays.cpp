class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> pref(n + 1, 0);
        pref[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            pref[i] = pref[i - 1] + arr[i - 1];
        }
        int result = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int k = 0; i + k <= n; k += 2)
            {
                //   cout << i + k << " " << pref[i + k] << " " << i << " " << pref[i - 1] << endl;
                result += pref[i + k] - pref[i - 1];
            }
        }
        return result;
    }
};