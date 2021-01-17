class Solution
{
private:
    int calc(int x)
    {
        int result = 0;
        while (x > 0)
        {
            x /= 2;
            ++result;
        }
        return result;
    }
    int calc2(int x)
    {
        int result = 0;
        if (x % 2 == 1)
            ++result;
        while (x > 0)
        {
            x /= 2;
            if (x % 2 == 1)
                ++result;
        }
        return result;
    }

public:
    int minOperations(vector<int> &nums)
    {
        int max_pow = 0;
        int result = 0;
        for (auto &x : nums)
        {
            int tmp = calc(x);
            max_pow = max(max_pow, tmp);
        }
        //cout << "max_pow " << max_pow << endl;
        for (auto &x : nums)
        {
            // cout <<x <<" " << calc2(x) << endl;
            result += calc2(x);
        }
        result += max_pow - 1;
        return result;
    }
};