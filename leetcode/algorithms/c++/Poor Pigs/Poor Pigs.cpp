class Solution
{
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest)
    {
        int T = minutesToTest / minutesToDie + 1;
        int x = 0;
        while (pow(T, x) < buckets)
            ++x;
        return x;
    }
};