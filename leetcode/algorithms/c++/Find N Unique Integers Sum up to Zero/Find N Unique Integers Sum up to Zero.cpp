class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> result;
        int sum = 0;
        for (int i = 1; i < n; i++)
        {
            sum += i;
            result.push_back(i);
        }
        result.push_back(-sum);
        return result;
    }
};