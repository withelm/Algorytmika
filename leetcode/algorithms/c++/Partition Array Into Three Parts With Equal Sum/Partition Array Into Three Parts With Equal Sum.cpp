class Solution
{
public:
    bool canThreePartsEqualSum(vector<int> &arr)
    {
        int n = arr.size();
        if (n < 2)
            return false;
        vector<int> pref(n, arr[0]);
        vector<int> suf(n, arr[n - 1]);
        map<int, int> baseSuf;
        int globalSum = arr[0];
        for (int i = 1; i < n; i++)
        {
            pref[i] = pref[i - 1] + arr[i];
            globalSum += arr[i];
        }
        if (globalSum % 3 != 0)
            return false;
        ++baseSuf[arr[n - 1]];
        for (int i = n - 2; i >= 0; i--)
        {
            suf[i] = suf[i + 1] + arr[i];
            ++baseSuf[suf[i]];
        }

        for (int i = 0; i < n; i++)
        {
            --baseSuf[suf[i]];

            if (globalSum - 2 * pref[i] == pref[i] && baseSuf[pref[i]] > 0)
                if (2 * pref[i] == pref[i])
                {
                    if (baseSuf[pref[i]] > 1)
                        return true;
                }
                else
                    return true;
        }
        return false;
    }
};