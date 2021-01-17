class Solution
{
public:
    bool canMakeArithmeticProgression(vector<int> &arr)
    {

        if (arr.size() <= 2)
            return true;
        sort(arr.begin(), arr.end());

        int div = arr[1] - arr[0];
        for (int i = 1; i < arr.size(); i++)
        {
            if (div != arr[i] - arr[i - 1])
                return false;
        }
        return true;
    }
};