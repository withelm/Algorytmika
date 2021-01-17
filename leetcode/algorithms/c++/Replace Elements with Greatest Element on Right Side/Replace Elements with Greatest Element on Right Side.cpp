class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        vector<int> result;
        for (int i = 0; i < arr.size(); i++)
        {
            int res = -1;
            for (int j = i + 1; j < arr.size(); j++)
            {
                res = max(res, arr[j]);
            }
            result.push_back(res);
        }
        return result;
    }
};