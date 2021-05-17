class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        vector<int> pref;
        pref.push_back(0);
        int n = cardPoints.size();
        vector<int> suff(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            pref.push_back(pref[i] + cardPoints[i]);
        }
        for (int i = n - 1; i >= 0; i--)
        {
            suff[i] = suff[i + 1] + cardPoints[i];
        }

        int res = 0;
        for (int i = 0; i <= k; i++)
        {
            res = max(res, pref[i] + suff[n - k + i]);
        }
        return res;
    }
};