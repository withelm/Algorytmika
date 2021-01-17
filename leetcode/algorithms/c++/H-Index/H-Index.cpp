class Solution
{

public:
    int hIndex(vector<int> &citations)
    {
        sort(citations.begin(), citations.end());
        int currentCount = 0;
        int length = citations.size();
        for (int i = citations.size() - 1; i >= 0; i--)
        {
            currentCount = length - i;

            if (currentCount - 1 >= citations[i])
            {
                return currentCount - 1;
            }
        }

        return currentCount;
    }
};