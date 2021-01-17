class Solution
{
public:
    int findTheDistanceValue(vector<int> &arr1, vector<int> &arr2, int d)
    {
        int r = 0;

        for (auto &x : arr1)
        {
            int cnt = 0;
            for (auto y : arr2)
            {
                if (abs(x - y) <= d)
                {
                    ++cnt;
                    break;
                }
            }
            if (cnt == 0)
                ++r;
        }
        return r;
    }
};