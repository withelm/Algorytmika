// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        long long int begin = 0;
        long long int end = n;
        while (begin < end)
        {

            long long int mid = (begin + end) / 2;
            if (isBadVersion(mid))
            {
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }
        }
        if (isBadVersion(begin))
            return begin;
        return begin + 1;
    }
};