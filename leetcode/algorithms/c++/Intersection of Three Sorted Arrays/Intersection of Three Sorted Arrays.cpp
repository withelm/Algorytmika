class Solution
{
public:
    vector<int> arraysIntersection(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3)
    {
        vector<int> r(2000 + 10, 0);
        for (auto &x : arr1)
            ++r[x];
        for (auto &x : arr2)
            ++r[x];
        for (auto &x : arr3)
            ++r[x];

        vector<int> result;
        for (int i = 0; i < 2000 + 10; i++)
        {
            if (r[i] == 3)
                result.push_back(i);
        }

        return result;
    }
};