class Solution
{
public:
    int missingNumber(vector<int> &arr)
    {
        vector<int> r;
        int n = arr.size();
        int art = 0;
        if (arr[1] - arr[0] >= 0)
            art = min(arr[1] - arr[0], arr[2] - arr[1]);
        else
            art = max(arr[1] - arr[0], arr[2] - arr[1]);

        for (int i = 0; i + 1 < n; i++)
        {
            if (arr[i] + art != arr[i + 1])
                return arr[i] + art;
        }
        return arr[0];
    }
};