class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        sort(arr.begin(), arr.end());
        map<int, vector<vector<int>>> base;
        int n = arr.size();

        for (int i = 0; i < n - 1; i++)
        {

            base[abs(arr[i] - arr[i + 1])].push_back({arr[i], arr[i + 1]});
        }
        return base.begin()->second;
    }
};