class Solution
{
public:
    int minSwaps(vector<int> &data)
    {
        int one = 0;
        int n = data.size();
        for (int i = 0; i < n; i++)
            one += data[i] == 1;
        int result = 1e9;
        int curr = 0;
        int index = 0;
        for (; index < one; index++)
        {
            curr += data[index] == 1;
        }

        result = min(result, one - curr);
        while (index < n)
        {
            if (data[index] == 1)
                ++curr;
            if (data[index - one] == 1)
                --curr;
            result = min(result, one - curr);
            ++index;
        }
        return result;
    }
};