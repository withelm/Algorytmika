class Solution
{
public:
    static inline int findNumbers(vector<int> &nums)
    {
        int r = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            r += licz(nums[i]) % 2 == 0 ? 1 : 0;
        }
        return r;
    }

    static inline int licz(int n)
    {
        if (n == 0)
            return 0;
        return licz(n / 10) + 1;
    }
};