class Solution
{
public:
    vector<int> transformArray(vector<int> &arr)
    {
        int n = arr.size() - 1;
        int m = 25000;
        vector<int> r;
        while (m--)
        {
            r.clear();
            r.push_back(arr[0]);
            for (int i = 1; i < n; i++)
            {
                if (arr[i - 1] > arr[i] && arr[i + 1] > arr[i])
                    r.push_back(arr[i] + 1);
                else if (arr[i - 1] < arr[i] && arr[i + 1] < arr[i])
                    r.push_back(arr[i] - 1);
                else
                    r.push_back(arr[i]);
            }
            r.push_back(arr[n]);
            arr = r;
        }

        return r;
    }
};