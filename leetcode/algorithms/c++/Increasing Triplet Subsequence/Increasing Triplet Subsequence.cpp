class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        long long int fs = 1LL << 33;
        long long int sec = fs;
        for (auto i : nums)
        {
            if (i <= fs)
            {
                fs = i;
            }
            else if (i <= sec)
            {
                sec = i;
            }
            else
                return true;
        }
        return false;
    }
};