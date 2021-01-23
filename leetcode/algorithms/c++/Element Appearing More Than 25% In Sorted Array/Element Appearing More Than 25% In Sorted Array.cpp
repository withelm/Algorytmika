class Solution
{
public:
    int findSpecialInteger(vector<int> &arr)
    {
        int n = arr.size();
        int begin = 0;
        int val = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (val != arr[i])
            {

                if (i - begin > n / 4)
                    return val;
                begin = i;
                val = arr[i];
            }
        }
        return val;
    }
};