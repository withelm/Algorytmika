class Solution
{
public:
    int maximumUnits(vector<vector<int>> &boxTypes, int truckSize)
    {
        sort(boxTypes.begin(), boxTypes.end(),
             [](const vector<int> &a, const vector<int> &b) -> bool {
                 return a[1] > b[1];
             });

        int result = 0;
        int index = 0;
        int n = boxTypes.size();
        while (truckSize > 0 && index < n)
        {
            int toGet = min(boxTypes[index][0], truckSize);

            result += toGet * boxTypes[index][1];
            truckSize -= toGet;
            ++index;
        }
        return result;
    }
};