class Solution
{
public:
    bool kLengthApart(vector<int> &nums, int k)
    {
        if (k == 0)
            return true;

        int last = -k - k;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {

                if (i - last <= k)
                    return false;
                last = i;
            }
        }
        return true;
    }
};